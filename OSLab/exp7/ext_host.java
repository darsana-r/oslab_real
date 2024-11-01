import java.io.*;
import java.util.*;
import java.net.*;
import java.lang.*;

public class ext_host{
	public static void main(String args[]) throws UnknownHostException{
		try{
			InetAddress IP=InetAddress.getByName(args[0]);
			System.out.println("IP address of "+args[0]+ " is:"+IP.getHostAddress());
		}catch(Exception e){
			System.out.println("Exception :"+e.getMessage());
		}
	}	
}

/*
OUTPUT

pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp7$ javac ext_host.java
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp7$ java ext_host www.google.com
IP address of www.google.com is:216.58.203.4

*/
