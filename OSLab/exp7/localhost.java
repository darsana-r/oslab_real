import java.io.*;
import java.util.*;
import java.net.*;
import java.lang.*;

public class localhost{
	public static void main(String args[]) throws UnknownHostException{
		try{
			InetAddress address=InetAddress.getLocalHost();
			System.out.println("IP address of localhost is:"+address.getHostAddress());
		}catch(Exception e){
			System.out.println("Exception :"+e.getMessage());
		}
	}	
}

/*
OUTPUT

pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp7$ javac localhost.java
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp7$ java localhost
IP address of localhost is:127.0.1.1

*/
