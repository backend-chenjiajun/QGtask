package com.cjj.util;

import java.io.InputStream;
import java.sql.*;
import java.util.Properties;

/**
 * @description 操作数据库的工具类
 */
public class JdbcUtils {

    /**
     *
     * @description 获取数据库连接
     * @return connection
     *
     */
    public static Connection getConnection() throws Exception {
	//通过系统类的加载器读取配置文件中的四个基本信息
        InputStream is =  ClassLoader.getSystemClassLoader().getResourceAsStream("jdbc.properties");

        Properties pros = new Properties();
        pros.load(is);
	//提供另外三个连接的基本信息
        String user = pros.getProperty("user");
        String password = pros.getProperty("password");
        String ur1 = pros.getProperty("ur1");
	//连接数据库库
        return DriverManager.getConnection(ur1, user, password);
    }

    /**
     * @description 关闭连接和Statement和ResultSet的操作
     *
     */
    public static void classResource(Connection connection, Statement statement,ResultSet resultSet){
        try {
            if(statement != null) {
                statement.close();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        try {
            if(connection!=null) {
                connection.close();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        try {
            if(resultSet!=null) {
                resultSet.close();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }


    }


}
