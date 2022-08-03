import java.util.Scanner;
import java.util.concurrent.TimeUnit;
import java.util.ArrayList;
import java.util.Random;
import java.util.Calendar;
import java.text.SimpleDateFormat;

//T042 - JASON LEONARDO SUTIOSO

public class Application {
	
	public static ArrayList<String> names = new ArrayList<String>();
	public static ArrayList<String> usernames = new ArrayList<String>();
	public static ArrayList<String> passwords = new ArrayList<String>();
	public static ArrayList<Integer> gameId = new ArrayList<Integer>();
	public static ArrayList<String> games = new ArrayList<String>();
	public static ArrayList<String> descs = new ArrayList<String>();
	public static ArrayList<Integer> sizes = new ArrayList<Integer>();
	public static ArrayList<String> lastUpdate = new ArrayList<String>();
	public static ArrayList<String> statuses = new ArrayList<String>();
	public static ArrayList<String> tempUsers = new ArrayList<String>();
	public static ArrayList<Integer> speeds = new ArrayList<Integer>();
	public static int currPos;
	public static int gameAmount = 6;
	
	public static void delay(int milisec)
	{
	    try
	    {
	        Thread.sleep(milisec);
	    }
	    catch(InterruptedException ex)
	    {
	        Thread.currentThread().interrupt();
	    }
	}
	
    public static final String DATE_FORMAT_NOW = "dd/MM/yyyy HH:mm:ss";
    
    public static String currDate() {
	    Calendar cal = Calendar.getInstance();
	    SimpleDateFormat sdf = new SimpleDateFormat(DATE_FORMAT_NOW);
	    return sdf.format(cal.getTime());
    }
	
	public static void defAcc() {
		names.add("Olaf");
		usernames.add("Orchard123");
		passwords.add("Snowman1234");
		
		names.add("Moana");
		usernames.add("Island1954");
		passwords.add("Boat1234");
		
		names.add("Anna");
		usernames.add("LittlePrincess54");
		passwords.add("Castle1234");
		
		names.add("Elsa");
		usernames.add("IceQueen1");
		passwords.add("Freeze1234");
		
		names.add("Rudolf");
		usernames.add("Reindeer687");
		passwords.add("Christ1234");
		
		names.add("Nick Wylde");
		usernames.add("NickTheWyldeFox");
		passwords.add("NickisWylde123");
	}
	
	public static void defGames() {
		games.add("Fly Guyz");
		descs.add("Totally not a rip-off of Fall Guys. Please don't sue us.");
		lastUpdate.add("09/01/2019 10:50:20");
		sizes.add(154062);
		
		games.add("Popper Tower 6");
		descs.add("Pop those balloons and protect your tower!");
		lastUpdate.add("10/03/2012 10:55:01");
		sizes.add(278648);
		
		games.add("Lavorant");
		descs.add("A competitive shooter with character classes!");
		lastUpdate.add("12/05/2019 02:14:09");
		sizes.add(8353231);
		
		games.add("Symmetry Dash");
		descs.add("A fun and addictive platformer with catchy music! Don't rage please!");
		lastUpdate.add("01/02/2011 09:00:01");
		sizes.add(654827);
		
		games.add("MiniCraft: Sumatra Edition");
		descs.add("The popular block sandbox game with the new Cave Update! Written in the Sumatra programming language.");
		lastUpdate.add("05/10/2020 09:00:01");
		sizes.add(255255);
		
		games.add("Pekamon Armor and Dagger");
		descs.add("Have to catch all of them! Astrid Catchem is on his way to become a Pekamon Master!");
		lastUpdate.add("07/08/2020 09:00:01");
		sizes.add(3485001);
		
		for(int i = 1; i <= gameAmount; i++) {
			gameId.add(i);
			statuses.add("Available");
			tempUsers.add(usernames.get(i - 1));
			speeds.add(10000);
		}
		
	}
	
	public static void storeScreen() {
		int tableLength = 113;
		while(true) {
			System.out.println("\nWelcome to Steamz Marketplace!");
			System.out.println("You can uninstall a game if that game has already been downloaded.\n");
			for(int i = 0; i < tableLength; i++) System.out.print("-");
		
			System.out.format("\n|%-3s|%-40s|%-10s %2s|%-20s|%-10s|%-20s|\n",
					"ID", "Game", "Size", " ", "Developer", "Status", "Last update");
			for(int i = 0; i < tableLength; i++) System.out.print("-");
			System.out.println();
			for(int i = 0; i < gameAmount; i++) {
				System.out.format("|%3d|%-40s|%10d %2s|%-20s|%-10s|%20s|\n",
						gameId.get(i), games.get(i), sizes.get(i), "KB", tempUsers.get(i), statuses.get(i), lastUpdate.get(i));
			}
			for(int i = 0; i < tableLength; i++) System.out.print("-");
			System.out.println("\n1. Download game\n2. View description\n0. Exit\n");
			System.out.print("Enter >> ");
			Scanner inp = new Scanner(System.in);
			String act = inp.nextLine();
			if(act.equals("1")) {
				Scanner inp2 = new Scanner(System.in);
				System.out.print("\nEnter game ID to download (0 to cancel) >> ");
				int down = inp2.nextInt();
				while(down < 0 || down > gameAmount) {
					System.out.print("\n[ID not valid] Enter game ID to download (0 to cancel) >> ");
					down = inp2.nextInt();
				}
				if(down != 0) {
					if(statuses.get(down-1).equals("Available")) {
						System.out.println("\nDownload " + games.get(down-1) + " [" + sizes.get(down-1) + "KB]?");
						System.out.print("Enter (y/n) >> ");
						String acc = inp2.nextLine();
						String acc1 = inp2.nextLine();
						System.out.println();
						if(acc1.equals("y")) {
							for(double i = 0; i <= sizes.get(down-1); i += speeds.get(currPos)) {
								System.out.format("Downloading... %.1f%%\n", (i/sizes.get(down-1)) * 100.0);
								System.out.println("Size downloaded: " + (int)i + " KB/" + sizes.get(down-1) + " KB");
								delay(250);
							}
							System.out.println("Downloading... 100.0%");
							System.out.println("Size downloaded: " + sizes.get(down-1) + " KB/" + sizes.get(down-1) + " KB");
							statuses.set(down - 1, "Downloaded");
							System.out.println("\n" + games.get(down-1) + " has been downloaded.\n");
							System.out.print("Type in any key to dismiss >> ");
							String ph = inp2.nextLine();
						}
					}
					else {
						System.out.println("\n" + games.get(down-1) + " has already been downloaded. Do you want to uninstall it?");
						System.out.print("Enter (y/n) >> ");
						Scanner inp3 = new Scanner(System.in);
						String del = inp3.nextLine();
						if(del.equals("y")) {
							for(int i = 0; i <= 100; i += 20) {
								System.out.println("Uninstalling... " + i + "%");
								delay(500);
							}
						statuses.set(down-1, "Available");
						System.out.println("\n" + games.get(down-1) + " has been uninstalled.");
						System.out.print("Type any key to dismiss >> ");
						String ph = inp3.nextLine();
						}
					}
				}
			}
			else if(act.equals("2")) {
				Scanner inp2 = new Scanner(System.in);
				System.out.print("\nEnter game ID to view description >> ");
				int view = inp2.nextInt();
				while(view < 1 || view > gameAmount) {
					System.out.print("\n[ID not valid] Enter game ID to view descripiton >> ");
					view = inp2.nextInt();
				}
				System.out.println("\nGame title: " + games.get(view-1));
				System.out.println("Developer: " + tempUsers.get(view-1));
				System.out.println("Size: " + sizes.get(view-1) + " KB");
				System.out.println("Description: " + descs.get(view-1));
				System.out.print("\nType in any key to dismiss >> ");
				Scanner inp3 = new Scanner(System.in);
				String ph = inp3.nextLine();
			}
			else if(act.equals("0")) break;
		}
	}
	
	public static void addGameScreen() {
		System.out.print("[Add a game to Steamz]\n\nGame ID (Numbers only) >> ");
		Scanner inp3 = new Scanner(System.in);
		int idIn = inp3.nextInt();
		if(!gameId.contains(idIn) && idIn != 0) {
			Scanner inp4 = new Scanner(System.in);
			System.out.print("Game name (Max. 25 characters) >> ");
			String gameIn = inp4.nextLine();
			while(gameIn.length() > 25) {
				System.out.print("[Game name too long!] Game name >> ");
				gameIn = inp4.nextLine();
			}
			System.out.print("Game description >> ");
			String descIn = inp4.nextLine();
			System.out.print("Game size (KB) (1 to 100000000 kB) >> ");
			int sizeIn = inp4.nextInt();
			while(sizeIn > 100000000 || sizeIn <= 0) {
				System.out.print("[INVALID FILE SIZE] Game size (KB) >> ");
				sizeIn = inp4.nextInt();
			}
			games.add(gameIn);
			tempUsers.add(usernames.get(currPos));
			descs.add(descIn);
			sizes.add(sizeIn);
			statuses.add("Available");
			lastUpdate.add(currDate());
			gameId.add(idIn);
			gameAmount++;
			System.out.println("\nGame successfully added!\n");
			delay(2000);
	
		}
	}
	
	public static void updateGameScreen() {
		int tableLength = 82;
		while(true) {
			System.out.println("\n[Update Games]\n");
			for(int i = 0; i < tableLength; i++) System.out.print("-");
		
			System.out.format("\n|%-3s|%-40s|%-10s %2s|%-20s|\n",
					"ID", "Game", "Update size", "", "Last update");
			for(int i = 0; i < tableLength; i++) System.out.print("-");
			System.out.println();
			for(int i = 0; i < gameAmount; i++) {
				if(statuses.get(i).equals("Downloaded")) {
					System.out.format("|%3d|%-40s|%11d %2s|%20s|\n",
						 gameId.get(i), games.get(i), (int)Math.ceil(0.2 * (double)sizes.get(i)), "KB", lastUpdate.get(i));
				}
			}
			for(int i = 0; i < tableLength; i++) System.out.print("-");
			Scanner inp = new Scanner(System.in);
			System.out.print("\nEnter ID to update game (0 to exit) >> ");
			int update = inp.nextInt();
			if(update != 0) {
				while(update < 1 || update > gameAmount || statuses.get(update-1).equals("Available")) {
					System.out.println("\n[Invalid ID] Enter ID to update game (0 to exit) >> ");
					update = inp.nextInt();
				}
				int updateSize = (int)Math.ceil(0.2 * (double)sizes.get(update-1));
				System.out.println("\nDo you want to update " + games.get(update-1) + " [" + updateSize + " KB]?");
				System.out.print("Enter (y/n) >> ");
				Scanner inp2 = new Scanner(System.in);
				String accept = inp2.nextLine();
				System.out.println();
				if(accept.equals("y")) {
					for(double i = 0; i <= updateSize; i += speeds.get(currPos)) {
						System.out.format("Updating... %.1f%%\n", (i/updateSize) * 100.0);
						System.out.println("Size downloaded: " + (int)i + " KB/" + updateSize + " KB");
						delay(250);
					}
					System.out.println("Updating... 100.0%");
					System.out.println("Size downloaded: " + updateSize + " KB/" + updateSize + " KB");
					lastUpdate.set(update-1, currDate());
					Scanner inp3 = new Scanner(System.in);
					System.out.print("\n" + games.get(update-1) + " has been updated.\n\nType any key to dismiss >> ");
					String ph = inp3.nextLine();
				}
			}
			else {
				break;
			}
		}
	}
	
	public static void deleteGameScreen() {
		int tableLength = 61;
		while(true) {
			System.out.println("\n[Delete Games]\nDelete your game from the store.\n");
			for(int i = 0; i < tableLength; i++) System.out.print("-");
		
			System.out.format("\n|%-3s|%-40s|%-10s %2s|\n",
					"ID", "Game", "Update size", "");
			for(int i = 0; i < tableLength; i++) System.out.print("-");
			System.out.println();
			for(int i = 0; i < gameAmount; i++) {
				if(tempUsers.get(i).equals(usernames.get(currPos))) {
					System.out.format("|%3d|%-40s|%11d %2s|\n",
						 gameId.get(i), games.get(i), sizes.get(i), "KB");
				}
			}
			for(int i = 0; i < tableLength; i++) System.out.print("-");
			Scanner inp = new Scanner(System.in);
			System.out.print("\nEnter ID to remove game (0 to exit) >> ");
			int delete = inp.nextInt();
			if(delete != 0) {
				while(delete < 1 || delete > gameAmount || !tempUsers.get(delete-1).equals(usernames.get(currPos))) {
					System.out.println("\n[Invalid ID] Enter ID to remove game (0 to exit) >> ");
					delete = inp.nextInt();
				}
				System.out.println("\nDo you want to remove " + games.get(delete-1) + " listing from Steamz?");
				System.out.print("Enter (y/n) >> ");
				Scanner inp2 = new Scanner(System.in);
				String accept = inp2.nextLine();
				System.out.println();
				if(accept.equals("y")) {
					System.out.println("Removing " + games.get(delete-1) + " from Steamz...");
					delay(5000);
					System.out.println("\n" + games.get(delete-1) + " removed from Steamz listing.\n");
					tempUsers.remove(delete-1);
					games.remove(delete-1);
					sizes.remove(delete-1);
					gameId.remove(delete-1);
					statuses.remove(delete-1);
					descs.remove(delete-1);
					lastUpdate.remove(delete-1);
					gameAmount--;
					System.out.print("Type in any key to dismiss >> ");
					Scanner inp3 = new Scanner(System.in);
					String ph = inp3.nextLine();
				}
			}
			else {
				break;
			}
		}
	}
	
	public static void profileScreen() {
		while(true) {
			System.out.println("\n[Your Profile]\n");
			System.out.println("Name: " + names.get(currPos));
			System.out.println("Steamz username: " + usernames.get(currPos));
			System.out.println("--------------------------------------");
			System.out.println("1. Change name\n2. Change username\n3. Change password\n0. Exit\n");
			System.out.print("Enter >> ");
			Scanner inp = new Scanner(System.in);
			String choose = inp.nextLine();
			if(choose.equals("1")) {
				Scanner inp2 = new Scanner(System.in);
				System.out.print("\nEnter new name >> ");
				String newName = inp2.nextLine();
				names.set(currPos, newName);
				System.out.println("\nName changed successfully.\n");
			}
			else if(choose.equals("2")) {
				Scanner inp2 = new Scanner(System.in);
				System.out.print("\nEnter new username >> ");
				String newUser = inp2.nextLine();
				usernames.set(currPos, newUser);
				System.out.println("\nUsername changed successfully.\n");
			}
			else if(choose.equals("3")) {
				Scanner inp2 = new Scanner(System.in);
				System.out.print("\nEnter new username >> ");
				String newPass = inp2.nextLine();
				passwords.set(currPos, newPass);
				System.out.println("\nPassword changed successfully.\n");
			}
			else if(choose.equals("0")) break;
		}
	}
	
	public static void internetSpeedScreen() {
		while(true) {
			System.out.println("\n[IndiHome Dashboard]\n");
			System.out.println("Current speed: " + speeds.get(currPos) + " kBps");
			System.out.println("-----------------------------");
			System.out.println("[IndiHome Paket Phoenix]\n");
			System.out.println("1. 10000 kBps\n2. 30000 kBps\n3. 75000 kBps\n4. 200000 kBps\n5. 1000000 kBps\n");
			System.out.println("[IndiHome Paket Custom]\n");
			System.out.print("6. Custom speed\n\n0. Exit\n\nEnter >> ");
			
			Scanner inp = new Scanner(System.in);
			String indiHome = inp.nextLine();
			
			if(indiHome.equals("1")) {
				speeds.set(currPos, 10000);
				System.out.println("\nChanged speed to " + speeds.get(currPos) + " kBps for " + usernames.get(currPos) + ".\n");
				delay(2000);
			}
			else if(indiHome.equals("2")) {
				speeds.set(currPos, 30000);
				System.out.println("\nChanged speed to " + speeds.get(currPos) + " kBps for " + usernames.get(currPos) + ".\n");
				delay(2000);
			}
			else if(indiHome.equals("3")) {
				speeds.set(currPos, 75000);
				System.out.println("\nChanged speed to " + speeds.get(currPos) + " kBps for " + usernames.get(currPos) + ".\n");
				delay(2000);
			}
			else if(indiHome.equals("4")) {
				speeds.set(currPos, 200000);
				System.out.println("\nChanged speed to " + speeds.get(currPos) + " kBps for " + usernames.get(currPos) + ".\n");
				delay(2000);
			}
			else if(indiHome.equals("5")) {
				speeds.set(currPos, 1000000);
				System.out.println("\nChanged speed to " + speeds.get(currPos) + " KBps for " + usernames.get(currPos) + ".\n");
				delay(2000);
			}
			else if(indiHome.equals("6")) {
				Scanner inp2 = new Scanner(System.in);
				System.out.print("\nEnter custom speed (5000 kBps - 1000000 kBps) >> ");
				int speed = inp2.nextInt();
				while(speed < 5000 || speed > 1000000) {
					System.out.print("[Invalid speed] Enter custom speed (5000 kBps - 1000000 kBps) >> ");
					speed = inp2.nextInt();
				}
				speeds.set(currPos, speed);
				System.out.println("\nChanged speed to " + speeds.get(currPos) + " KBps for " + usernames.get(currPos) + ".\n");
				delay(2000);
			}
			else if(indiHome.equals("0")) break;
			
		}
	}
	
	public static void steamzScreen() {
		String currUser = usernames.get(currPos);
		String currName = names.get(currPos);
		defGames();
		while(true) {
			System.out.println("\n[Steamz]\nHello, " + currName + " (" + currUser + ")");
			System.out.println("=============================");
			System.out.println("1. Download game\n2. Add game\n3. Update game\n4. Delete game\n5. Update profile\n6. Change download speed\n0. Log out\n");
			System.out.print("Enter >> ");
			Scanner inp = new Scanner(System.in);
			String choice = inp.nextLine();
			if(choice.equals("1")) {
				storeScreen();
			}
			else if(choice.equals("2")) {
				addGameScreen();
			}
			else if(choice.equals("3")) {
				updateGameScreen();
			}
			else if(choice.equals("4")) {
				deleteGameScreen();
			}
			else if(choice.equals("5")) {
				profileScreen();
			}
			else if(choice.equals("6")) {
				internetSpeedScreen();
			}
			else if(choice.equals("0")) {
				break;
			}
		}
	}
	
	public static void loginScreen() {
		defAcc();
		while(true) {
			System.out.println("\nWelcome to STEAMZ!\n(c) Vulve Corp.\n");
			System.out.println("[1] Login\n[2] Register\n[3] Exit\n");
			System.out.print("Enter >> ");
			Scanner inp = new Scanner(System.in);
			String choice = inp.nextLine();
			
			if(choice.equals("1")) {
				System.out.println("\n[Login to Steamz]\nEnter your credentials.\n");
				System.out.print("Username >> ");
				Scanner inp2 = new Scanner(System.in);
				String userIn = inp2.nextLine();
				System.out.print("Password >> ");
				String passIn = inp2.nextLine();
				if(usernames.contains(userIn) && passwords.contains(passIn)) {
					currPos = usernames.indexOf(userIn);
					steamzScreen();
				}
				else {
					System.out.println("That account does not exist.\n");
					delay(2500);
				}
			}
			else if(choice.equals("2")) {
				System.out.println("\n[Register Steamz Account]\nRegister a new account.\n");
				System.out.print("Username (6 - 20 characters) >> ");
				Scanner inp2 = new Scanner(System.in);
				String userIn = inp2.nextLine();
				while(userIn.length() < 6 || userIn.length() > 20) {
					System.out.print("[Username too long or too short!] Username >> ");
					userIn = inp2.nextLine();
				}
				System.out.print("Password (6 - 30 characters) >> ");
				String passIn = inp2.nextLine();
				while(passIn.length() < 6 || passIn.length() > 30) {
					System.out.print("[Password too long or too short!] Password >> ");
					passIn = inp2.nextLine();
				}
				System.out.println("\nAccount successfully created! Enter your name.\n");
				System.out.print("Enter name >> ");
				String nameIn = inp2.nextLine();
				names.add(nameIn);
				usernames.add(userIn);
				passwords.add(passIn);
				speeds.add(10000);
				System.out.println("\nThank you for registering! You can now log in!\n");
				delay(2500);
			}
		}
	}
	
	public static void main (String [] args) {
		loginScreen();

	}
}
