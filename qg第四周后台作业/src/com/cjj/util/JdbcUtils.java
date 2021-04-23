package com.cjj.util;

import java.sql.*;


/**
 *
 * @description 操作数据库的工具类
 * @author CJJ
 * @create 2021-04-05 9:39
 */
public class JdbcUtils {

  private static ConnectionPool connectionPool = new ConnectionPool();
    /**
     *
     * @description 获取数据库连接
     * @return connection
     * @throws SQLException
     */
    public static Connection getConnection() throws SQLException {

        return connectionPool.getConnection();
    }


    /**
     *
     * @description 资源关闭函数重载
     * @param connection
     * @param statement
     * @param resultSet
     */
    public static void resourceClose(Connection connection,Statement statement,ResultSet resultSet){

        //资源关闭前先确认是否为空
        //先关闭结果集
        try {
            if(resultSet!=null) {
                resultSet.close();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        //再关闭语句
        try {
            if(statement!=null) {
                statement.close();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        //最后关闭连接
        try {
            if(connection!=null) {
                connection.close();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

}
