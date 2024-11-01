import java.io.*;
import java.util.*;
import java.net.*;
import java.lang.*;

public class tcp_client{
	public static void main(String args[]) throws IOException{
		try{
			Socket sokt=new Socket(InetAddress.getLocalHost(),1234);
			System.out.print("Enter the message to the server:");
			Scanner from_client=new Scanner(System.in);

			String msg=from_client.nextLine();
			PrintWriter output=new PrintWriter(sokt.getOutputStream(),true);
			output.println(msg);

			Scanner from_server=new Scanner(sokt.getInputStream());
			String reply=from_server.nextLine();
			System.out.println("Reply message from server :"+ reply);
			sokt.close();
		}catch(Exception e){
			System.out.println(e.getMessage());
		}
		
	}	
}

/*
OUTPUT

(first compile server then client)

pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp10$ javac tcp_client.java
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp10$ java tcp_client
Enter the message to the server:Hi,This is the message from client
Reply message from server :message from client got successfully

pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp10$ javac tcp_server.java
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp10$ java tcp_server
waiting for connection...
Message from client :Hi,This is the message from client
Enter the reply message: message from client got successfully

*/

