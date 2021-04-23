package com.cjj.view;

import com.cjj.controller.LoginController;
import com.cjj.util.Utility;

/**
 * @author CJJ
 * @create 2021-04-22 22:02
 */
public class LoginView {

    public static void loginView(){

        boolean loopFlag = true;
        while (loopFlag){

            System.out.println("==============================================================================");
            System.out.println("=                                                                            =");
            System.out.println("==============================================================================");
            System.out.println("=                              1---登录                                       =");
            System.out.println("=                              2---用户注册                                    =");
            System.out.println("=                              3---退出系统                                    =");
            System.out.println("==============================================================================");
            System.out.println("==============================================================================");
            System.out.println("请输入（1-4）进行操作：");
            char menu = Utility.readMenuSelection();
            switch (menu){
                case '1':
                    System.out.println("请输入用户名：");
                    String userName = Utility.readKeyBoard(20,false);
                    System.out.println("请输入密码：");
                    String password = Utility.readKeyBoard(20,false);

                    LoginController.userLogin(userName,password);
                    break;
                case '2':
                    //用户注册
                    System.out.println("请输入用户名：");
                     String name = Utility.readKeyBoard(20,false);
                    System.out.println("请输入密码：");
                      String password1 = Utility.readKeyBoard(20,false);
                    LoginController.userRegister(name,password1);
                    break;
                case '3':
                    System.out.println("确认退出？Y/N");
                    if(Utility.readConfirmSelection()) {
                        System.out.println("期待您的再次使用~");
                        System.out.println("正在退出···");
                        Utility.readReturn();
                        loopFlag = false;
                    }else{
                        System.out.println("请输入（1-4）进行选择：");
                    }
                    break ;
                default:
                    System.out.println("输入错误！请重新输入：");
            }
        }

    }
}
