package com.cjj.util;

import javax.sql.DataSource;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.lang.reflect.Proxy;
import java.sql.*;
import java.util.LinkedList;
import java.util.Properties;
import java.util.logging.Logger;

/**
 * @author CJJ
 * @create 2021-04-20 14:59
 */
public class ConnectionPool implements DataSource {

    /**
     * 存放数据库连接
     */
   public static LinkedList<Connection> connectionPool = new LinkedList<>();

   //加载配置文件
   static{
       //调用系统类的加载器读取配置文件中的基本信息
       InputStream inputStream = ClassLoader.getSystemClassLoader().getResourceAsStream("jdbc.properties");
       Properties pros = new Properties();
       try {
           pros.load(inputStream);
           //读取相关登录信息
           String user = pros.getProperty("user");
           String password = pros.getProperty("password");
           String ur1 = pros.getProperty("ur1");
           int initSize = 10;
           //初始化十个连接
           for(int i = 0;i<initSize;i++){
               Connection connection = DriverManager.getConnection(ur1, user, password);
               //添加连接
               connectionPool.add(connection);
           }
       } catch (IOException | SQLException e) {
           e.printStackTrace();
       }
   }


    /**
     * 获取数据库连接
     * @return
     * @throws SQLException
     */
    @Override
    public Connection getConnection() throws SQLException {

        if(connectionPool.size()>0){
            //从集合中获取连接
           final Connection connection = connectionPool.removeFirst();

            // //使用动态代理，当调用Connection.close()的时候自动将连接放回连接池中
            return (Connection) Proxy.newProxyInstance
                    (ConnectionPool.class.getClassLoader(),
                    connection.getClass().getInterfaces(),
                            (proxy, method, args) -> {
                        if("close".equals(method.getName())){
                            //如果调用了close方法则将连接返回连接池中
                            connectionPool.add(connection);
                        }else{
                            return method.invoke(connection, args);
                        }
                        return null;
                    });
        }else {
            throw new RuntimeException("数据库访问频繁，请稍后再试");
        }
    }

    @Override
    public Connection getConnection(String username, String password) throws SQLException {
        return null;
    }

    @Override
    public <T> T unwrap(Class<T> iface) throws SQLException {
        return null;
    }

    @Override
    public boolean isWrapperFor(Class<?> iface) throws SQLException {
        return false;
    }

    @Override
    public PrintWriter getLogWriter() throws SQLException {
        return null;
    }

    @Override
    public void setLogWriter(PrintWriter out) throws SQLException {

    }

    @Override
    public void setLoginTimeout(int seconds) throws SQLException {

    }

    @Override
    public int getLoginTimeout() throws SQLException {
        return 0;
    }

    @Override
    public Logger getParentLogger() throws SQLFeatureNotSupportedException {
        return null;
    }
}
