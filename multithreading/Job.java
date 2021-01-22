package com.company.Threads;

/**
 * in job 3 we can not use multiple inheritance so we can use runnable interface
 */
public class Job extends Parent implements Runnable {
    Printer ref;
    final String doc;
    public Job(Printer ref,String doc) {
        this.ref = ref;
        this.doc = doc;
    }

    @Override
    public void run() {
        synchronized (doc){
            ref.printDocument(10,doc);
        }

    }
}

