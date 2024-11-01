import java.io.*;
import java.util.*;
import java.net.*;
import java.lang.*;

public class tcp_server{
	public static void main(String args[]) throws IOException{
		try{
			ServerSocket serversocket=new ServerSocket(1234);
			System.out.println("waiting for connection...");
			Socket link=serversocket.accept();

			Scanner from_client=new Scanner(link.getInputStream());
			String inp=from_client.nextLine();

			System.out.println("Message from client "+inp);

			System.out.print("Enter the reply message: ");
			Scanner from_user=new Scanner(System.in);
			String reply=from_user.nextLine();

			PrintWriter output=new PrintWriter(link.getOutputStream(), true);
			output.println(reply);
			link.close();
		}catch(IOException e){
			System.out.println(e);
		}	
	}	
}

