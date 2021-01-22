package com.company.Threads;

public class Printer {
    synchronized public void printDocument(int numberOfCopy, String docName) {
        for (int i = 0; i < numberOfCopy; i++) {
            System.out.println(">> Printing " + docName + " " + i);
        }
    }
}
