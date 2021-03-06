// Timothy Rine and Joseph Nguyen
// Baumgartner
// CSC4101 Project 1

import java.io.*;

class BooleanLit extends Node 
{
    private boolean booleanVal;

    public BooleanLit(boolean b) 
    {
        booleanVal = b;
    }

    public void print(int n) 
    {
        for (int i = 0; i < n; i++)
        {
            System.out.print(" ");
        }
    
        if (booleanVal) 
        {
            System.out.println("#t");
        } 
    
        else 
        {
            System.out.println("#f");
        }
    }
}