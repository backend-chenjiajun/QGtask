package com.cjj.dao;

import com.cjj.entity.User;

import java.sql.Connection;
import java.sql.Date;

/**
 * 此接口用于规范针对user表的常用操作
 * @author CJJ
 * @create 2021-04-05 16:46
 */
public interface UserDao {

    /**
     * 针对user表插入信息
     * @param user
     */
    void insert( User user);

    /**
     * 根据id获得User对象
     * @param userName
     * @param password
     * @return
     */
    User getUser(String userName,String password);

    /**
     * 获得数量
     * @param userName
     * @param password
     * @return
     */
    int getCount(String userName,String password);



}
