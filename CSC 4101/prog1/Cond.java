// Timothy Rine and Joseph Nguyen
// Baumgartner
// CSC4101 Project 1

import java.io.*;

class Cond extends Special 
{
    //Default constructor
    public Cond()
    {}

    void print(Node t, int n, boolean p) 
    {
        if(!p)
        {
            System.out.print("(");
        }
        System.out.println("cond");

    	if(t.getCdr() != null)
        {
	    printElements((Cons)t.getCdr(), n+4, false);
    	}
            for(int i = 0; i < n; i++)
            {
                System.out.print(" ");
            }
    	System.out.print(")");
    }

    void printElements(Cons t, int n, boolean isQuote) 
    {
    	if (isQuote) 
        {
            System.out.print(" ");
            t.getCar().printQuote(n, false);
    	} 

        else 
        {
            for(int i = 0; i < n; i++)
            {
                System.out.print(" ");
            }
    	t.getCar().print(n);
    	System.out.println();
    	}
    	
    	if(t.getCdr() != null)

        {
            printElements((Cons)t.getCdr(), n, isQuote);
        }
    }

    void printQuote(Node t, int n, boolean p) 
    {
	if(!p)
        {
            System.out.print("(");
        }
        System.out.print("cond ");
        
	if(t.getCdr() != null)
        {
	    printElements((Cons)t.getCdr(), 0, true);
            System.out.print(")");
        }
    }
}