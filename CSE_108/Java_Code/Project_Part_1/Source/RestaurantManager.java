import java.util.ArrayList;
import java.util.HashMap;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class RestaurantManager {
    private ArrayList<Restaurant> restaurantsDatabase = new ArrayList<>();
    private ArrayList<Food> fooditemsDatabase = new ArrayList<>();

    private int lastusedrestaurantID;
    private final int initrestcount;
    private final int initialfoodcount;
    private final String RESTUARANT_DATABASE_FILE;
    private final String FOOD_DATABASE_FILE;

    RestaurantManager(String RESTUARANT_DATABASE_FILE, String FOOD_DATABASE_FILE) {
        this.RESTUARANT_DATABASE_FILE = RESTUARANT_DATABASE_FILE;
        this.FOOD_DATABASE_FILE = FOOD_DATABASE_FILE;
        readDataBase();
        lastusedrestaurantID = 1;
        initrestcount = restaurantsDatabase.size();
        initialfoodcount = fooditemsDatabase.size();
    }

    private void readDataBase() {
        // Read data from the files here.
        try {
            BufferedReader restaurantReader = new BufferedReader(new FileReader(RESTUARANT_DATABASE_FILE));
            while (true) {
                String line = restaurantReader.readLine();
                if ((line == null)) {
                    break;
                }
                Restaurant tempRestaurant = new Restaurant(line);
                restaurantsDatabase.add(tempRestaurant);
            }
            restaurantReader.close();

            BufferedReader foodReader = new BufferedReader(new FileReader(FOOD_DATABASE_FILE));
            while (true) {
                String line = foodReader.readLine();
                if (line == null) {
                    break;
                }

                Food tempFood = new Food(line);
                fooditemsDatabase.add(tempFood);
            }
            foodReader.close();
            
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
        // This 2 statement will be after file read write.
    }

    public boolean AddRestaurant(Restaurant restauranttoadd) {
        // Returns false if restaurant name already exists in the database.
        boolean flag = true;
        for (Restaurant i : restaurantsDatabase) {
            if (restauranttoadd.equals(i)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            restaurantsDatabase.add(restauranttoadd);
        }
        return flag;
    }

    public int generateUniqueID() {
        int ID = lastusedrestaurantID;
        boolean flag=true;
        while (flag) {
            for (Restaurant i : restaurantsDatabase) {
                if (i.getId() == ID) {
                    flag=true;
                    break;
                }
                else{
                    flag=false;
                }
            }
            if(flag)
            {
                ID++;
            }
        }

        lastusedrestaurantID = ID;
        return ID;
    }

    public int AddFood(Food foodtoadd) {
        // Return False if a food with same name exists in the database already.
        // if the restaurant id is not present in the restaurant database.----still
        // uncomplete
        int flag = 1;
        for (Food i : fooditemsDatabase) {

            if (foodtoadd.equals(i)) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            for (Restaurant i : restaurantsDatabase) {
                if (i.getId() == foodtoadd.getRestaurantId()) {
                    flag = 1;
                    break;
                } else {
                    flag = -1;
                }
            }
        }
        if (flag == 1) {
            fooditemsDatabase.add(foodtoadd);
        }
        return flag;
    }

    // Restaurant Search methods.
    public ArrayList<Restaurant> SearchRestaurantbyName(String Restaurantname) {
        ArrayList<Restaurant> outArrayList = new ArrayList<>();
        for (Restaurant i : restaurantsDatabase) {
            if (i.DoesNameContains(Restaurantname)) {
                outArrayList.add(i);
            }
        }
        return outArrayList;
    }

    public ArrayList<Restaurant> SearchRestaurantbyScore(double score1, double score2) {
        if (score1 > score2) {
            double temp = score1;
            score1 = score2;
            score2 = temp;
        }
        ArrayList<Restaurant> outArrayList = new ArrayList<>();
        for (var i : restaurantsDatabase) {
            if (i.getScore() >= score1 && i.getScore() <= score2) {
                outArrayList.add(i);
            }
        }
        return outArrayList;
    }

    public ArrayList<Restaurant> SearchRestaurantbyCatagory(String Catagory) {
        /*
         * Each catagory is split in word based on space and each sepereted word is
         * matched
         * with the given catagory name
         */
        ArrayList<Restaurant> outArrayList = new ArrayList<>();
        for (Restaurant i : restaurantsDatabase) {
            if (i.isinCatagories(Catagory)) {
                outArrayList.add(i);
            }
        }
        return outArrayList;

    }

    public ArrayList<Restaurant> SearchRestaurantbyPrice(String Pricerange) {
        ArrayList<Restaurant> outArrayList = new ArrayList<>();
        for (Restaurant i : restaurantsDatabase) {
            if (i.getPrice().equals(Pricerange)) {
                outArrayList.add(i);
            }
        }
        return outArrayList;
    }

    public ArrayList<Restaurant> SearchRestaurantbyZipCode(String ZipCode) {

        ArrayList<Restaurant> outArrayList = new ArrayList<>();
        for (Restaurant i : restaurantsDatabase) {
            if (i.getZipCode().equalsIgnoreCase(ZipCode)) {
                outArrayList.add(i);
            }
        }
        return outArrayList;
    }

    public HashMap<String, ArrayList<String>> CatagoryWiseRestaurant() {
        /*
         * This function create a hashmap with catagory as key
         * and arraylist of restaurants as value.The condition is that
         * the restaurants should have the catagory used as key present in there
         * catagories
         */
        HashMap<String, ArrayList<String>> outHashMap = new HashMap<>();
        for (var restaurant : restaurantsDatabase) {
            for (var catagory : restaurant.getCatagories()) {
                if ((!catagory.equals("")) && !outHashMap.containsKey(catagory)) {
                    outHashMap.put(catagory, new ArrayList<String>());
                }
            }
        }
        for (String catagory : outHashMap.keySet()) {
            for (Restaurant restaurant : restaurantsDatabase) {
                if (restaurant.isinCatagories(catagory)) {
                    outHashMap.get(catagory).add(restaurant.getName());
                }
            }
        }

        return outHashMap;
        // return null;
    }

    // FOOD SEARCH METHODS.
    public ArrayList<Food> SearchFoodbyName(String Foodname) {
        ArrayList<Food> outArrayList = new ArrayList<>();
        for (var i : fooditemsDatabase) {
            if (i.DoesNameContains(Foodname)) {
                outArrayList.add(i);
            }
        }

        return outArrayList;
    }

    public ArrayList<Food> SearchFoodbyNameinRestaurant(String Foodname, String Restaurantname) {

        // System.out.println("No such food item with this name on the menu of this
        // restaurant");
        // Search in database if the food name is in the database already and the
        // restaurant name is in the database already
        ArrayList<Food> outArrayList = new ArrayList<>();
        for (var i : fooditemsDatabase) {
            if (i.DoesNameContains(Foodname)
                    && IDtoRestaurantName(i.getRestaurantId()).toLowerCase().contains(Restaurantname.toLowerCase())) {
                outArrayList.add(i);
            }
        }
        return outArrayList;
    }

    public ArrayList<Food> SearchFoodbyCatagory(String Catagory) {
        ArrayList<Food> outArrayList = new ArrayList<>();
        for (var i : fooditemsDatabase) {
            if (i.getCatagory().toLowerCase().contains(Catagory.toLowerCase())) {
                outArrayList.add(i);
            }
        }
        return outArrayList;
    }

    public ArrayList<Food> SearchFoodbyCatagoryinRestaurant(String Restaurantname, String Catagory) {
        ArrayList<Food> outArrayList = new ArrayList<>();
        for (var i : fooditemsDatabase) {
            if (i.getCatagory().toLowerCase().contains(Catagory.toLowerCase())
                    && IDtoRestaurantName(i.getRestaurantId()).equalsIgnoreCase(Restaurantname)) {
                outArrayList.add(i);
            }
        }
        return outArrayList;
        ///Wrong output.
    }

    public ArrayList<Food> SearchFoodbyRange(double range1, double range2) {
        if (range1 > range2) {
            double temp = range1;
            range1 = range2;
            range2 = temp;
        }
        ArrayList<Food> outArrayList = new ArrayList<>();
        for (var i : fooditemsDatabase) {
            if (i.getPrice() >= range1 && i.getPrice() <= range2) {
                outArrayList.add(i);
            }
        }
        return outArrayList;
    }

    public ArrayList<Food> SearchFoodbyRangeinRestaurant(double range1, double range2, String Restaurantname) {
        if (range1 > range2) {
            double temp = range1;
            range1 = range2;
            range2 = temp;
        }
        ArrayList<Food> outArrayList = new ArrayList<>();
        for (var i : fooditemsDatabase) {
            if (i.getPrice() >= range1 && i.getPrice() <= range2
                    && IDtoRestaurantName(i.getRestaurantId()).equalsIgnoreCase(Restaurantname)) {
                outArrayList.add(i);
            }
        }
        return outArrayList;
    }

    public ArrayList<Food> CostliestFoodinRestaurant(String Restaurantname) {
        ArrayList<Food> outArrayList = new ArrayList<>();
        double maximumCost = fooditemsDatabase.get(0).getPrice();
        for (var i : fooditemsDatabase) {
            if (IDtoRestaurantName(i.getRestaurantId()).equalsIgnoreCase(Restaurantname)) {
                if (i.getPrice() > maximumCost) {
                    maximumCost = i.getPrice();
                }
            }
        }
        for (var i : fooditemsDatabase) {
            if (IDtoRestaurantName(i.getRestaurantId()).equalsIgnoreCase(Restaurantname)) {
                if (i.getPrice() == maximumCost) {
                    outArrayList.add(i);
                }
            }
        }
        return outArrayList;
    }

    public HashMap<String, Integer> RestaurantListwithFoodCount() {
        // Use HashMap to complete this task.
        HashMap<String, Integer> map = new HashMap<>();
        for (var i : restaurantsDatabase) {
            map.put(IDtoRestaurantName(i.getId()), 0);
        }
        for (var i : fooditemsDatabase) {
            map.put(IDtoRestaurantName(i.getRestaurantId()), map.get(IDtoRestaurantName(i.getRestaurantId())) + 1);
        }
        return map;
    }

    public String IDtoRestaurantName(int Id) {
        for (var i : restaurantsDatabase) {
            if (i.getId() == Id) {
                return i.getName();
            }
        }
        return null;
    }

    public int RestaurantNametoID(String Restaurantname/* Case insensitive */) {
        for (var i : restaurantsDatabase) {
            if (i.getName().equalsIgnoreCase(Restaurantname))
                return i.getId();
        }
        return -1;
    }

    public String FoodcontentforConsole(Food obj) {
        String outString;
        outString = "Name : " + obj.getName() + "\n    Catagory : " + obj.getCatagory() + "\n    Price : " + obj.getPrice()
                + "\n    Restaurand Name : " + IDtoRestaurantName(obj.getRestaurantId());

        return outString;
    }

    public void WriteFinalDatabases() {
        /*
         * Write all data of restaurant database and food databse to files.
         * If the database is unchanged(The length of the arraylist is same,since there
         * is no remove food or resturant method),
         * Then no need to write to database.
         */
        if (initrestcount != restaurantsDatabase.size()) {
            // Code for file writing.
            try {
                BufferedWriter Restaurantwriter = new BufferedWriter(new FileWriter(RESTUARANT_DATABASE_FILE));

                for (int i = 0; i < restaurantsDatabase.size(); i++) {
                    Restaurantwriter.write(restaurantsDatabase.get(i).Restaurantcontentforfile());
                    //Restaurantwriter.newLine();
                    Restaurantwriter.write(System.lineSeparator());
                    // null word is being written.
                }

                Restaurantwriter.close();
            } catch (IOException e) {
                System.out.println(e.getMessage());
            }
        }
        if (initialfoodcount != fooditemsDatabase.size()) {
            try {
                BufferedWriter Foodwriter = new BufferedWriter(new FileWriter(FOOD_DATABASE_FILE));

                for (int i = 0; i < fooditemsDatabase.size(); i++) {
                    Foodwriter.write(fooditemsDatabase.get(i).Foodcontentforfile());
                    Foodwriter.newLine();
                }

                Foodwriter.close();
            } catch (IOException e) {
                System.out.println(e.getMessage());
            }
        }
    }

}
