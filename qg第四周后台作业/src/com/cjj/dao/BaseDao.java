package com.cjj.dao;

import com.cjj.util.JdbcUtils;

import java.lang.reflect.Field;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @description 封装了针对数据库表的通用的增删改查操作
 * @author CJJ
 * @create 2021-04-05 10:04
 */
public abstract class BaseDao {

    /**
     * 增删改通用函数
     * @param connection
     * @param sql
     * @param args
     */
    public void update(Connection connection, String sql, Object ... args)  {

        PreparedStatement preparedStatement = null;
        try {
            //预编译sql语句
            preparedStatement = connection.prepareStatement(sql);
            //填充占位符
            for(int i = 0;i < args.length; i++){
                preparedStatement.setObject(i+1,args[i]);
            }
            //执行
            preparedStatement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            //关闭资源
            JdbcUtils.resourceClose(null,preparedStatement,null);
        }
    }

    
    public void update( String sql, Object ... args)  {

        Connection connection = null;
        PreparedStatement preparedStatement = null;
        try {
            //获取连接
            connection = JdbcUtils.getConnection();
            //预编译sql语句
            preparedStatement = connection.prepareStatement(sql);
            //填充占位符
            for(int i = 0;i < args.length; i++){
                preparedStatement.setObject(i+1,args[i]);
            }
            //执行
            preparedStatement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            //关闭资源
            JdbcUtils.resourceClose(connection,preparedStatement,null);
        }
    }
    /**
     *
     * @description 返回一条查询记录
     * @param clazz
     * @param sql
     * @param args
     * @param <T>
     * @return
     */
    public <T> T getInstance(Class<T> clazz,String sql,Object ... args)  {

        Connection connection = null;
        PreparedStatement preparedStatement = null;
        ResultSet resultSet = null;
        try {
            connection = JdbcUtils.getConnection();
            //预编译sql语句,返回preparedStatement的实例
             preparedStatement = connection.prepareStatement(sql);
            for (int i = 0; i<args.length; i++){
                preparedStatement.setObject(i+1,args[i]);
            }
            //执行操作
            resultSet = preparedStatement.executeQuery();
            //获取结果集的元数据
            ResultSetMetaData rsMetaData = resultSet.getMetaData();
            //通过ResultSetMetaData获得结果集中的列数
            int columnCount = rsMetaData.getColumnCount();
            if(resultSet.next()){
                T t = clazz.newInstance();
                for(int i = 0;i<columnCount;i++){
                    Object columnValue = resultSet.getObject(i + 1);
                    //获取每个列的列名
                    String columnLabel = rsMetaData.getColumnLabel(i + 1);
                    //通过反射，给指定对象指定的属性赋值为columnValue
                    Field field = clazz.getDeclaredField(columnLabel);
                    field.setAccessible(true);
                    field.set(t,columnValue);
                }
                return t;
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            //资管关闭
            JdbcUtils.resourceClose(connection,preparedStatement,resultSet);
        }
        return null;
    }



    /**
     * @description 用于查询多条记录
     * @param clazz
     * @param sql
     * @param args
     * @param <T>
     * @return
     */
    public <T> List<T> getForList(Class<T> clazz,String sql,Object ... args) {

        Connection connection = null;
        PreparedStatement preparedStatement = null;
        ResultSet resultSet = null;
        try {
            connection = JdbcUtils.getConnection();
             preparedStatement = connection.prepareStatement(sql);
            for(int i = 0; i < args.length; i++){
                preparedStatement.setObject( i+1,args[i]);
            }
            resultSet = preparedStatement.executeQuery();
            ResultSetMetaData rsMetaData = resultSet.getMetaData();
            int columnCount = rsMetaData.getColumnCount();
            //创建List集合用来存放数据
            ArrayList<T> list = new ArrayList<>();
            while (resultSet.next()){
                T t = clazz.newInstance();

                for(int i = 0; i < columnCount; i++){
                    Object columnValue = resultSet.getObject(i + 1);

                    String columnLabel = rsMetaData.getColumnLabel(i + 1);

                    Field field = clazz.getDeclaredField(columnLabel);
                    field.setAccessible(true);
                    field.set(t,columnValue);
                }
                //查询到的数据放入集合中
                list.add(t);
            }
            return list;
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            JdbcUtils.resourceClose(connection,preparedStatement,resultSet);
        }
        return null;
    }

    /**
     * @description 用于查询特殊值
     * @param sql
     * @param args
     * @param <T>
     * @return
     */
    public <T> T getValue(String sql,Object ... args){

        Connection connection = null;
        PreparedStatement preparedStatement= null;
        ResultSet resultSet = null;
        try {
            connection = JdbcUtils.getConnection();
             preparedStatement = connection.prepareStatement(sql);

            for(int i = 0; i < args.length; i++){
                preparedStatement.setObject(i+1,args[i]);
            }
          resultSet = preparedStatement.executeQuery();

            if(resultSet.next()){
                return (T) resultSet.getObject(1);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            JdbcUtils.resourceClose(connection,preparedStatement,resultSet);
        }
        return null;

    }
}
