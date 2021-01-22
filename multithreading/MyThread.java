package com.company.Threads;

/**
 * we implement threads in this class extends Thread class
 */
public class MyThread extends Thread {
    @Override
    public void run() {
        for (int i = 0; i < 10; i++) {
            System.out.println("Printer 1 " + i);
        }
    }

}

/**
 *  super class for job3
 */
class Parent{

}