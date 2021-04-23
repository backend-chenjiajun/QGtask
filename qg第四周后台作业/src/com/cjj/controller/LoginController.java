package com.cjj.controller;

import com.cjj.entity.User;
import com.cjj.service.LoginService;
import com.cjj.service.LoginServiceImpl;
import com.cjj.util.Utility;

/**
 * @author CJJ
 * @create 2021-04-22 21:53
 */
public class LoginController {

        public static void userRegister(String userName,String password){

            //创建UserServiceImpl对象来调用相关方法
            LoginServiceImpl loginService = new LoginServiceImpl();

            loginService.insert(new User(userName,password));
            System.out.println("注册成功！");
        }

        public static void userLogin(String userName,String password){
            //创建UserServiceImpl对象来调用相关方法
            LoginServiceImpl loginService = new LoginServiceImpl();
            if(loginService.isUser(userName,password)){
                System.out.println("登录成功！");
            }else{
                System.out.println("用户不存在！");
            }
        }
}
