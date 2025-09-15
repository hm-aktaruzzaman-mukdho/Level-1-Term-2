public class MainApp {
    public static void main(String[] args) {
        final RestaurantManager DataPool=new RestaurantManager("restaurantout.txt","menuout.txt");
        WindowManager windows=new WindowManager(DataPool);
        windows.MainWindow();
    }
}