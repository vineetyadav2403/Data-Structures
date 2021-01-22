package com.company;

import com.company.Threads.Job;
import com.company.Threads.Printer;

public class Main {
    /**
     * main method represents main thread
     * @param args this is useless for use we are not using it.
     */
    public static void main(String[] args) throws InterruptedException {
        /**
         * job 1
         */
        System.out.println("======Application started=======");
        Printer printer = new Printer();
        /**
         * job 2 is run the printer one
         */
        Thread job2 = new Thread(new Job(printer,"Vineet"));

        /**
         * job 3 is run the printer two
         */
        Runnable runnable = new Job(printer,"manish");
        Thread job3 = new Thread(runnable);

        /**
         * in this scenario we can see that two thread are using same printer
         *
         * we must need to synchronize them
         */
        job2.start();
        job3.start();
        /**
         * job 3 is end of the program
         * Wait for job 2 and job 3 have done
         */
        job2.join();
        job3.join();

        System.out.println("Application is terminated");
    }

}
