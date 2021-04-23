package com.cjj.dao;

import com.cjj.entity.User;


/**
 * @author CJJ
 * @create 2021-04-22 21:39
 */
public class UserDaoImpl extends BaseDao implements UserDao{
    @Override
    public void insert(User user) {
        String sql = "insert into user(user_name,password) values(?,?)";
        update(sql,user.getUserName(),user.getPassword());
    }

    @Override
    public User getUser(String userName, String password) {
        String sql = "select * from user where user_name = ? and password = ?";
        return getInstance(User.class,sql,userName,password);
    }

    @Override
    public int getCount(String userName, String password) {

        String sql = "select count(*) from user where user_name = ? and password = ?";
        return ((Number)getValue(sql,userName,password)).intValue();
    }
}
