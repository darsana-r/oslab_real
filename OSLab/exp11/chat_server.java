import java.io.*;
import java.util.*;
import java.net.*;
import java.lang.*;

public class chat_server{
	public static void main(String args[]) throws IOException{
		try{
			String reply;
			String inp;
			ServerSocket serversocket=new ServerSocket(1234);
			System.out.println("waiting for connection...");
			Socket link=serversocket.accept();
			while(true){

				Scanner from_client=new Scanner(link.getInputStream());
				inp=from_client.nextLine();
				System.out.println("Message from client "+inp);

				System.out.print("Enter the reply message: ");
				Scanner from_user=new Scanner(System.in);
				reply=from_user.nextLine();
				PrintWriter output=new PrintWriter(link.getOutputStream(), true);
				output.println(reply);

				if(reply.equals("stop")||inp.equals("stop")){
					break;
				}	
			}

			link.close();
			
		}catch(IOException e){
			System.out.println(e);
		}	
	}	
}

