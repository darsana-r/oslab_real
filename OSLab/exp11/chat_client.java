import java.io.*;
import java.util.*;
import java.net.*;
import java.lang.*;

public class chat_client{
	public static void main(String args[]) throws IOException{
		try{
			String reply,msg;

			Socket sokt=new Socket(InetAddress.getLocalHost(),1234);
			while(true){
				
				System.out.print("Enter the message to the server:");
				Scanner from_client=new Scanner(System.in);
				
				msg=from_client.nextLine();
				PrintWriter output=new PrintWriter(sokt.getOutputStream(),true);
				output.println(msg);
				Scanner from_server=new Scanner(sokt.getInputStream());
				reply=from_server.nextLine();
				System.out.println("Reply message from server :"+ reply);
				if(reply.equals("stop")||msg.equals("stop")){
					break;
				}
				
			}
			sokt.close();
			
		}catch(Exception e){
			System.out.println(e.getMessage());
		}
		
	}	
}

/*
OUTPUT

pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp11$ javac chat_server.java
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp11$ java chat_server
waiting for connection...
Message from client hai
Enter the reply message: helo
Message from client stop
Enter the reply message: stop

pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp11$ javac chat_client.java
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp11$ java chat_client
Enter the message to the server:hai
Reply message from server :helo
Enter the message to the server:stop
Reply message from server :stop

*/
