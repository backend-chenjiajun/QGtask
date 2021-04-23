package com.cjj.service;

import com.cjj.entity.User;

/**
 * @author CJJ
 * @create 2021-04-22 21:48
 */
public interface LoginService {

    /**+
     *
     * @param userName
     * @param password
     * @return
     */
    User login(String userName, String password);

    /**
     *
     * @param user
     */
    void insert(User user);

    /**
     *
     * @param userName
     * @param password
     * @return
     */
    boolean isUser(String userName, String password);
}
