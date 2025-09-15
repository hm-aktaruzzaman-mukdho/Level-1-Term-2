import javafx.fxml.FXML;
import javafx.scene.control.TableView;

public class Controller {
    @FXML
    private TableView<Person> tableView; // Replace with your actual TableView type

    public void initialize() {
        // Create and start the server listener thread
        ServerListenerThread serverListenerThread = new ServerListenerThread(tableView, 12345); // Replace 12345 with your server's port
        serverListenerThread.start();
    }
}
