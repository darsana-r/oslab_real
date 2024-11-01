import java.io.*;
import java.util.*;
import java.net.*;
import java.lang.*;

public class server{
	public static void main(String args[]) throws IOException{
		try{
			ServerSocket serversocket=new ServerSocket(1234);
			System.out.println("waiting for connection...");
			Socket link=serversocket.accept();

			Scanner from_client=new Scanner(link.getInputStream());
			String inp=from_client.nextLine();
			System.out.println("Message from client:"+inp);
		
			PrintWriter output=new PrintWriter(link.getOutputStream(), true);
			output.println(inp);
			link.close();
		}catch(IOException e){
			System.out.println(e);
		}	
	}	
}

/*
OUTPUT

(first compile server then client)

pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp9$ javac client.java
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp9$ java client
Enter the message to the server:Hi Message from client                        
Return message from server :Hi Message from client

pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp9$ javac server.java
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp9$ java server
waiting for connection...
Return message from server which send by client:Hi Message from client


*/
