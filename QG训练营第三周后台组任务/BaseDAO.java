package com.cjj.dao;

import com.cjj.util.JdbcUtils;

import java.lang.reflect.Field;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

/**
 * 封装了针对于数据表的通用操作
 */
public abstract class BaseDAO {

    public int update(Connection conn,String sql,Object ... args)  {

        PreparedStatement ps = null;

        try {
            //预编译sql语句，返回PreparedStatement的实例
            ps = conn.prepareStatement(sql);
            //填充占位符
            for(int i = 0;i<args.length;i++){
                ps.setObject(i+1,args[i]);
            }
            //执行
            return ps.executeUpdate();
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            //关闭资源
            JdbcUtils.classResource(null,ps);
        }
        return 0;

    }

    //返回一条查询记录
    public <T> T getInstance(Connection conn,Class<T> clazz,String sql,Object...args){

        PreparedStatement ps = null;
        ResultSet rs = null;
        try {
         //预编译sql语句,返回preparedStatement的实例
            ps = conn.prepareStatement(sql);
            for(int i = 0;i<args.length;i++){
                ps.setObject(i+1,args[i]);
            }
	//执行操作
            rs = ps.executeQuery();
            //获取结果集的元数据
            ResultSetMetaData rsmd = rs.getMetaData();
            //通过ResultSetMetaData获得结果集中的列数
            int columnCount = rsmd.getColumnCount();
            if(rs.next()){
                T t = clazz.newInstance();
                for(int i = 0;i<columnCount;i++){
                    Object columValue = rs.getObject(i + 1);
         	   //获取每个列的列名
                    String columnLabel = rsmd.getColumnLabel(i + 1);
    	   //通过反射，给指定对象指定的属性赋值为columnValue
                    Field field = clazz.getDeclaredField(columnLabel);
                    field.setAccessible(true);
                    field.set(t,columValue);
                }
                return t;
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
          //资源关闭
            JdbcUtils.classResource(null, ps, rs);
        }
        return null;
    }


    //获得多条查询记录

    public <T> List<T> getForList(Connection conn,Class<T> clazz, String sql, Object...args){

        PreparedStatement ps = null;
        ResultSet rs = null;
        try {
            ps = conn.prepareStatement(sql);
            for(int i = 0;i<args.length;i++){
                ps.setObject(i+1,args[i]);
            }
            rs = ps.executeQuery();
            ResultSetMetaData rsmd = rs.getMetaData();
            int columnCount = rsmd.getColumnCount();

            //创建集合对象
            ArrayList<T> list = new ArrayList<>();
            while (rs.next()){
                T t = clazz.newInstance();
                //给t对象指定的属性赋值
                for(int i = 0;i<columnCount;i++){
                    Object columValue = rs.getObject(i + 1);

                    String columnLabel = rsmd.getColumnLabel(i + 1);

                    Field field = clazz.getDeclaredField(columnLabel);
                    field.setAccessible(true);
                    field.set(t,columValue);
                }
                list.add(t);
            }
            return list;
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            JdbcUtils.classResource(null, ps, rs);
        }
        return null;
    }

    //用于查询特殊值的方法

    public <T> T getValue(Connection conn,String sql,Object ... args)  {
        PreparedStatement ps = null;
        ResultSet rs = null;
        try {
            ps = conn.prepareStatement(sql);
            for(int i =0;i<args.length;i++)
            {
                ps.setObject(i+1,args[i]);
            }
	//执行
            rs = ps.executeQuery();
            if(rs.next()){
                return (T) rs.getObject(1);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
	//关闭资源
            JdbcUtils.classResource(null,ps,rs);
        }
        return null;
    }

}
