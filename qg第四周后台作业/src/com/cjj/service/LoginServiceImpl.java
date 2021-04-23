package com.cjj.service;

import com.cjj.dao.UserDao;
import com.cjj.dao.UserDaoImpl;
import com.cjj.entity.User;

/**
 * @author CJJ
 * @create 2021-04-22 21:49
 */
public class LoginServiceImpl implements LoginService{

    UserDao userDao = new UserDaoImpl();
    @Override
    public User login(String userName, String password) {
      return userDao.getUser(userName,password);
    }

    @Override
    public void insert(User user) {
        userDao.insert(user);
    }

    @Override
    public boolean isUser(String userName, String password) {
        int count = userDao.getCount(userName, password);
        return  count == 1;
    }
}
