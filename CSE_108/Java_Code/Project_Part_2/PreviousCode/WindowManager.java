import java.util.Scanner;
import java.util.ArrayList;
import java.util.HashMap;

public class WindowManager {
    private final RestaurantManager DataPool;

    private final Scanner scanner = new Scanner(System.in);

    WindowManager(RestaurantManager DataPool) {
        this.DataPool = DataPool;
    }

    public void MainWindow() {

        while (true) {

            System.out.println("\n    ------------ Main Menu ------------");
            System.out.println("--------------------------------------------");
            System.out.println("1) Search Restaurants");
            System.out.println("2) Search Food Items");
            System.out.println("3) Add Restaurant");
            System.out.println("4) Add Food Item to the Menu");
            System.out.println("5) Exit System");
            System.out.print("Enter choice from 1 to 5 : ");
            try {
                int choice = scanner.nextInt();
                scanner.nextLine();
                if (choice == 1) {
                    SearchRestaurantWindow();

                } else if (choice == 2) {
                    SearchFoodItemsWindow();

                } else if (choice == 3) {
                    AddRestaurantWindow();

                } else if (choice == 4) {
                    AddFoodItemWindow();

                } else if (choice == 5) {
                    DataPool.WriteFinalDatabases();
                    return;

                } else {
                    System.out.println("    !!! Wrong input.Enter choice from 1 to 5. !!!");
                    // System.out.print(" Enter a valid choice from 1 to 5 : ");
                }
            } 
            catch (Exception e) {
                System.out.println("        !!! Wrong input.Enter integer choice !!!");
                scanner.nextLine();
            }

        }
    }

    private void SearchRestaurantWindow() {

        while (true) {
            System.out.println("\n******** Restaurant Searching Options ********\n");
            System.out.println("1) By Name");
            System.out.println("2) By Score");
            System.out.println("3) By Category");
            System.out.println("4) By Price");
            System.out.println("5) By Zip Code");
            System.out.println("6) Different Category Wise List of Restaurants");
            System.out.println("7) Back to Main Menu");
            System.out.print("Enter choice from 1 to 7: ");
            try {
                int choice = scanner.nextInt();
                scanner.nextLine();
                if (choice == 1) {
                    SearchRestaurantbyNameWindow();
                } else if (choice == 2) {
                    SearchRestaurantbyScore();
                } else if (choice == 3) {
                    SearchRestaurantbyCatagoryWindow();
                } else if (choice == 4) {
                    SearchRestaurantbyPriceWindow();
                } else if (choice == 5) {
                    SearchRestaurantbyZipCodeWindow();
                } else if (choice == 6) {
                    CatagoryWiseRestaurantWindow();
                } else if (choice == 7) {
                    return;
                } else {
                    System.out.println("    !!! Wrong input choice. !!!");
                    // System.out.print("Enter valid choice from 1 to 7 :");
                }
            } catch (Exception e) {
                System.out.println("        !!! Wrong input.Enter integer choice !!!");
                scanner.nextLine();
            }
        }
    }

    private void SearchFoodItemsWindow() {

        while (true) {
            System.out.println("\n******** Food Item Searching Options ********\n");
            System.out.println("1) By Name");
            System.out.println("2) By Name in a Given Restaurant");
            System.out.println("3) By Category");
            System.out.println("4) By Category in a Given Restaurant");
            System.out.println("5) By Price Range");
            System.out.println("6) By Price Range in a Given Restaurant");
            System.out.println("7) Costliest Food Item(s) on the Menu in a Given Restaurant");
            System.out.println("8) List of Restaurants and Total Food Item on the Menu");
            System.out.println("9) Back to Main Menu");
            try {
                System.out.print("Enter choice from 1 to 9 : ");
                int choice = scanner.nextInt();
                scanner.nextLine();
                if (choice == 1) {
                    SearchFoodbyNameWindow();
                } else if (choice == 2) {
                    SearchFoodbyNameinRestaurantWindow();
                } else if (choice == 3) {
                    SearchFoodbyCatagoryWindow();
                } else if (choice == 4) {
                    SearchFoodbyCatagoryinRestaurantWindow();
                } else if (choice == 5) {
                    SearchFoodbyRangeWindow();
                } else if (choice == 6) {
                    SearchFoodbyRangeinRestaurantWindow();
                } else if (choice == 7) {
                    CostliestFoodinRestaurantWindow();
                } else if (choice == 8) {
                    FoodCountonRestaurantsWindow();
                } else if (choice == 9) {
                    return;
                } else {
                    System.out.println("    !!! Wrong input choice. !!!");
                    // System.out.println("Enter valid choice from 1 to 9 : ");
                }
            } catch (Exception e) {
                System.out.println("        !!! Wrong input.Enter integer choice !!!");
                scanner.nextLine();
            }
        }
    }

    private void AddRestaurantWindow() {
        Restaurant temprestaurant;

        int Id;
        String Name;
        double Score;
        String Pricerange;
        String ZipCode;
        ArrayList<String> Catagory = new ArrayList<>();

        System.out.println("\n******** Add a restaurant to the Database ********\n");
        // System.out.print(" Enter restaurant ID : ");
        // Id = scanner.nextInt();
        // scanner.nextLine();
        Id = DataPool.generateUniqueID();
        System.out.print("  Enter Name of the Restaurant : ");
        Name = scanner.nextLine();
        System.out.print("  Enter Score of the Restaurant : ");
        Score = scanner.nextDouble();
        scanner.nextLine();

        System.out.print("  Enter Price of the restaurant : ");
        while (true) {
            Pricerange = scanner.nextLine();
            // Check if the the price is made of $$$
            Boolean validprice = true;
            for (int i = 0; i < Pricerange.length(); i++) {
                if (Pricerange.charAt(i) != '$') {
                    validprice = false;
                    break;
                }
            }
            if (Pricerange.equals(""))
                validprice = false;
            if (validprice) {
                break;
            } else {
                System.out.print("  Enter valid price(Consisting only $ sign) : ");
            }

        }

        System.out.print("  Enter Zip Code of the Restaurant : ");
        ZipCode = scanner.nextLine();

        System.out.println("  Enter maximum 3 or minimum 1 catagory of the restaurant:");
        for (int i = 0; i < 3;) {
            boolean flag = true;
            System.out.print("  Enter catagory : ");
            String temp = scanner.nextLine();
            flag = !(temp.equals(""));// False if no input.
            if (flag) {
                Catagory.add(temp);
                i++;
            } else {
                if (i == 0) {
                    System.out.println("    !!! Enter at least one catagory !!! ");
                } else {
                    i++;
                }
            }
        }

        temprestaurant = new Restaurant(Id, Name, Score, Pricerange, ZipCode, Catagory);

        boolean flag = DataPool.AddRestaurant(temprestaurant);
        if (flag) {
            System.out.println("    !!! Restaurant is added successfully to the database !!!");
        } else {
            System.out.println("    !!! Restaurant name is already present in the database !!!");
        }
    }

    private void AddFoodItemWindow() {

        int RestaurantId;
        String Catagory;
        String Name;
        double Price;
        System.out.println("\n******** Add Food Items to Database ********\n");
        while (true) {
            System.out.print("  Enter Restaurant name of the food : ");
            String Restaurantname = scanner.nextLine();
            // scanner.nextLine();
            RestaurantId = DataPool.RestaurantNametoID(Restaurantname);
            System.out.print("  Enter Catagory of the food : ");
            Catagory = scanner.nextLine();
            System.out.print("  Enter name of the food : ");
            Name = scanner.nextLine();
            System.out.print("  Enter Price of the food : ");
            Price = scanner.nextDouble();
            scanner.nextLine();
            Food temporaryFood = new Food(RestaurantId, Catagory, Name, Price);
            int returnval = DataPool.AddFood(temporaryFood);
            if (returnval == 1) {
                System.out.println("    !!! Food item added to database Successfully. !!!");
                break;
            } else if (returnval == -1) {
                System.out.println(
                        "    !!! The restuanant name is not present in the database.Add the restaurant first !!!");
                System.out.println("  Do you want to add the restaurant?\n1. Yes\n2. No");
                int choice = scanner.nextInt();
                scanner.nextLine();
                if (choice == 1) {
                    AddRestaurantWindow();
                }
            } else {
                System.out.println("    !!! Food item is already present in the database. !!!");
                break;
            }
        }
    }

    public void SearchRestaurantbyNameWindow() {
        System.out.println("\n******** Search Resturants by name ********\n");
        System.out.print("  Enter Restaurant name :");
        String Restaurantname = scanner.nextLine();
        ArrayList<Restaurant> output = DataPool.SearchRestaurantbyName(Restaurantname);
        if (output.isEmpty()) {
            System.out.println("    !!! No such restaurant with name " + Restaurantname + " !!!");
        } else {
            System.out.println("        <--- Restaurants with name containing " + Restaurantname + " --->\n");
            for (Restaurant restaurant : output) {

                System.out.println(restaurant.RestaurantcontentforConsole());
                System.out.println();
            }
        }
    }

    public void SearchRestaurantbyScore() {
        System.out.println("\n******** Search a restaurant by Score range ********\n");
        System.out.print("  Enter 1st Score : ");
        double score1 = scanner.nextDouble();
        scanner.nextLine();
        System.out.print("  Enter 2nd Score : ");
        double score2 = scanner.nextDouble();
        scanner.nextLine();
        ArrayList<Restaurant> output = DataPool.SearchRestaurantbyScore(score1, score2);

        if (output.size() == 0) {
            System.out.println("    !!! No restaurants with score between " + score1 + " and " + score2 + " !!!");
        } else {
            System.out.println("        <--- Restaurants with Score between " + score1 + " and " + score2 + " --->\n");
            for (var i : output) {
                System.out.println("" + i.RestaurantcontentforConsole());
                System.out.println();
            }
        }
    }

    public void SearchRestaurantbyCatagoryWindow() {
        System.out.println("\n******** Search a restaurant by catagory ********\n");
        System.out.print("  Enter catagory : ");
        String Catagory = scanner.nextLine();
        ArrayList<Restaurant> output = DataPool.SearchRestaurantbyCatagory(Catagory);

        if (output.size() == 0) {
            System.out.println("    !!! No restaurants with catagory " + Catagory + " !!!");
        } else {
            System.out.println("        <--- Restaurants with catagory containing word " + Catagory + " --->");
            for (var i : output) {
                System.out.println("    " + i.getName());
            }
        }
    }

    public void SearchRestaurantbyPriceWindow() {
        System.out.println("\n******** Search a restaurant by Price ********");
        System.out.print("  Enter price : ");
        String price = scanner.next();
        scanner.nextLine();
        ArrayList<Restaurant> output = DataPool.SearchRestaurantbyPrice(price);

        if (output.size() == 0) {
            System.out.println("    !!! No restaurants with price " + price + " !!!");
        } else {
            System.out.println("        <--- Restaurants with price " + price + " --->\n");
            for (var i : output) {
                System.out.println("    " + i.getName());
            }
        }
    }

    public void SearchRestaurantbyZipCodeWindow() {
        System.out.println("\n******** Search a restaurant by zip code ********\n");
        System.out.print("    Enter zip code : ");
        String ZipCode = scanner.next();
        scanner.nextLine();
        ArrayList<Restaurant> output = DataPool.SearchRestaurantbyZipCode(ZipCode);

        if (output.size() == 0) {
            System.out.println("    !!! No restaurants with zip code " + ZipCode + " !!!");
        } else {
            System.out.println("        <--- Restaurants with zip code " + ZipCode + " --->\n");
            for (var i : output) {
                System.out.println("    " + i.getName());
            }
        }
    }

    public void CatagoryWiseRestaurantWindow() {
        System.out.println("\n************ Catagory wise restaurants ************\n");
        HashMap<String, ArrayList<String>> output = DataPool.CatagoryWiseRestaurant();
        for (var catagory : output.keySet()) {
            {
                System.out.print("    " + catagory + " : ");
                var restaurantnamelist = output.get(catagory);
                for (var restaurantname : restaurantnamelist) {
                    System.out.print(restaurantname + ", ");
                }
                System.out.println();
            }

        }
    }

    public void SearchFoodbyNameWindow() {
        System.out.println("\n******** Search Food Items by name ********\n");
        System.out.print("  Enter Food name :");
        String Foodname = scanner.nextLine();
        ArrayList<Food> output = DataPool.SearchFoodbyName(Foodname);

        if (output.size() == 0) {
            System.out.println("    !!! No food items with name " + Foodname + " !!!");
            System.out.println();
        } else {
            System.out.println("        <--- Food Items with name " + Foodname + " --->\n");
            for (var i : output) {
                System.out.println("    " + DataPool.FoodcontentforConsole(i));
                System.out.println();
            }
        }
    }

    public void SearchFoodbyNameinRestaurantWindow() {
        System.out.println("\n******** Search food by name in restaurant ********\n");
        System.out.print("  Enter Food name :");
        String Foodname = scanner.nextLine();
        System.out.print("  Enter Restaurant name :");
        String Restaurantname = scanner.nextLine();
        ArrayList<Food> output = DataPool.SearchFoodbyNameinRestaurant(Foodname, Restaurantname);

        if (output.size() == 0) {
            System.out.println(
                    "    !!! No food items with name " + Foodname + " in restaurant " + Restaurantname + " !!!");
            System.out.println();
        } else {
            System.out.println(
                    "        <--- Food Items with name " + Foodname + " in restaurant " + Restaurantname + " --->\n");
            for (var i : output) {
                System.out.println("    " + DataPool.FoodcontentforConsole(i));
                System.out.println();
            }
        }
    }

    public void SearchFoodbyCatagoryWindow() {
        System.out.println("\n******** Search Food Items by catagory ********\n");
        System.out.print("  Enter catagory : ");
        String Catagory = scanner.nextLine();
        ArrayList<Food> output = DataPool.SearchFoodbyCatagory(Catagory);

        if (output.size() == 0) {
            System.out.println("    !!! No food items with catagory " + Catagory + " !!!");
            System.out.println();
        } else {
            System.out.println("        <--- Food Items with catagory " + Catagory + " --->\n");
            for (var i : output) {
                System.out.println("    " + DataPool.FoodcontentforConsole(i));
                System.out.println();
            }
        }
    }

    public void SearchFoodbyCatagoryinRestaurantWindow() {
        System.out.println("\n******** Search food by catagory in restaurant ********\n");
        System.out.print("  Enter catagory : ");
        String Catagory = scanner.nextLine();
        System.out.print("  Enter Restaurant name : ");
        String Restaurantname = scanner.nextLine();
        ArrayList<Food> output = DataPool.SearchFoodbyCatagoryinRestaurant(Restaurantname, Catagory);

        if (output.isEmpty()) {
            System.out.println(
                    "    !!! No food items with catagory " + Catagory + " in restaurant " + Restaurantname + " !!!");
            System.out.println();
        } else {
            System.out.println(
                    "        <---Food Items with catagory " + Catagory + "in restaurant " + Restaurantname + "--->\n");
            for (var i : output) {
                System.out.println("    " + DataPool.FoodcontentforConsole(i));
                System.out.println();
            }
        }
    }

    public void SearchFoodbyRangeWindow() {
        System.out.println("\n******** Search Food Items by price range ********\n");
        System.out.print("  Enter 1st price : ");
        double range1 = scanner.nextDouble();
        scanner.nextLine();
        System.out.print("  Enter 2nd price : ");
        double range2 = scanner.nextDouble();
        scanner.nextLine();
        ArrayList<Food> output = DataPool.SearchFoodbyRange(range1, range2);

        if (output.size() == 0) {
            System.out.println("    !!! No food items with price between " + range1 + " and " + range2 + " !!!");
        } else {
            System.out.println("        <--- Food Items with price between " + range1 + " and " + range2 + " --->\n");
            for (var i : output) {
                System.out.println("    " + DataPool.FoodcontentforConsole(i));
                System.out.println();
            }
        }
    }

    public void SearchFoodbyRangeinRestaurantWindow() {
        System.out.println("\n******** Search Food Items by price range ********\n");
        System.out.print("  Enter 1st price : ");
        double range1 = scanner.nextDouble();
        scanner.nextLine();
        System.out.print("  Enter 2nd price : ");
        double range2 = scanner.nextDouble();
        scanner.nextLine();
        System.out.print("  Enter Restaurant name : ");
        String Restaurantname = scanner.nextLine();
        ArrayList<Food> output = DataPool.SearchFoodbyRangeinRestaurant(range1, range2, Restaurantname);

        if (output.size() == 0) {
            System.out
                    .println("    !!! No food items with price between " + range1 + " and " + range2 + " in restaurant "
                            + Restaurantname + " !!!");
        } else {
            System.out.println("        <--- Foods with price between " + range1 + " and " + range2 + " in restaurant "
                    + Restaurantname + "--- >\n");
            for (var i : output) {
                System.out.println("    " + DataPool.FoodcontentforConsole(i));
                System.out.println();
            }
        }
    }

    public void CostliestFoodinRestaurantWindow() {
        System.out.println("\n******** Costliest Food in Restaurant ********\n");
        System.out.print("Enter Restaurant name : ");
        String Restaurantname = scanner.nextLine();
        ArrayList<Food> output = DataPool.CostliestFoodinRestaurant(Restaurantname);
        if (output.isEmpty()) {
            System.out.println("    !!! No food item fresent in the database !!!");
        } else {
            System.out.println("        <--- Costliest Food on the list --->");
            for (var i : output) {
                System.out.println("    " + DataPool.FoodcontentforConsole(i));
                System.out.println();
            }
        }

    }

    public void FoodCountonRestaurantsWindow() {
        System.out.println("\n******** Food Count on Restaurant ********\n");
        System.out.println("    <--- Restaurants list with food count on them --->");
        HashMap<String, Integer> output = DataPool.RestaurantListwithFoodCount();
        for (var i : output.entrySet()) {
            System.out.println("    " + i.getKey() + " : " + i.getValue());
        }

    }
}
