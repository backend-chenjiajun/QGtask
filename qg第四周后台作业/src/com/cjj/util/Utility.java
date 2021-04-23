package com.cjj.util;

import java.util.Scanner;

/**
 * @author CJJ
 * @create 2021-04-06 15:03
 */
public class Utility {

    private static Scanner scanner = new Scanner(System.in);

    /**
     * @return
     * @description 该方法读取键盘，若用户输入‘1’-‘9’中的字符则返回输入的字符。
     */
    public static char readMenuSelection() {
        char selection;
        for (; ; ) {
            //限制输入数为1
            String s = readKeyBoard(1, false);
            //返回指定索引处的值
            selection = s.charAt(0);
            //判断是否为’1‘-’9‘
            if (selection < '1' || selection > '9') {
                System.out.println("输入错误！请重新输入：");
            } else {
                break;
            }
        }
        //返回输入的值
        return selection;
    }


    /**
     * @return char
     * @description 从键盘读取‘Y’或‘N’，并将其作为方法的返回值。
     */
    public static boolean readConfirmSelection() {

        char selection;
        for (; ; ) {
            //进行输入并限制输入数为1
            String str = readKeyBoard(1, false).toUpperCase();
            //返回索引处的值
            selection = str.charAt(0);
            //判断selection是否为’Y‘或’N‘中的一个
            if (selection == 'Y' || selection == 'N') {
                return selection == 'Y';
            } else {
                System.out.println("输入错误，请重新输入：");
            }
        }
    }

    /**
     * @description 该方法提示用户等待，直到用户按回车键后返回
     */
    public static void readReturn() {
        System.out.println("按回车键继续...");
        readKeyBoard(100, true);
    }

    /**
     * @param limit
     * @param blankReturn
     * @return
     * @description 该方法限制用户从键盘中输入的字符数
     */
    public static String readKeyBoard(int limit, boolean blankReturn) {
        String line = "";
        //遍历输入的字符串
        while (scanner.hasNextLine()) {
            line = scanner.nextLine();
            //若字符串长度为0
            if (line.length() == 0) {
                //判断是否是输入回车继续功能
                if (blankReturn) {
                    return line;
                } else {
                    continue;
                }
            }
            if (line.length() > limit) {
                //限制输入的长度不能大于自定的limit
                System.out.println("输入长度（不大于" + limit + "）错误：请重新输入：");
                continue;
            }
            break;
        }
        //返回输入的字符串
        return line;
    }

    /**
     * 返回确认
     *
     * @return
     */
    public static boolean exitConfirm() {

        //退出返回
        System.out.println("确认返回？Y/N");
        if (readConfirmSelection()) {
            System.out.println("正在返回···");
            Utility.readReturn();
            return true;
        }
        return false;
    }

    /**
     * 读取整型数据
     *
     * @return
     */
    public static long readKeyboard() {
        //将num数据类型定义为long型，防止输入超过整型的范围
        long num;
        while (true) {
            //判断输入是否合法
            if (scanner.hasNextInt()) {
                //输入整型数字
                num = scanner.nextInt();
                //读取最后一个换行字符
                scanner.nextLine();
                return num;
            } else {
                System.out.println("输入了非数字或输入过大！请重新输入：");
            }
            //清空缓存区
            scanner.nextLine();
        }
    }
}
