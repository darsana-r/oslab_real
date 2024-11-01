import java.io.*;
import java.util.*;
import java.net.*;
import java.lang.*;

public class client{
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
			System.out.println("Return message from server which send by client:"+ reply);
			sokt.close();
		}catch(Exception e){
			System.out.println(e.getMessage());
		}
		
	}	
}

