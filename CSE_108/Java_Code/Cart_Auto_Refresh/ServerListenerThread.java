import javafx.application.Platform;
import javafx.scene.control.TableView;

import java.io.ObjectInputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.List;

public class ServerListenerThread extends Thread {
    private TableView<Person> tableView; // Replace with your actual TableView type
    private int port; // Replace with your server's port number

    public ServerListenerThread(TableView<Person> tableView, int port) {
        this.tableView = tableView;
        this.port = port;
    }

    @Override
    public void run() {
        try {
            ServerSocket serverSocket = new ServerSocket(port);

            while (true) {
                Socket clientSocket = serverSocket.accept();
                ObjectInputStream objectInputStream = new ObjectInputStream(clientSocket.getInputStream());

                // Read the ArrayList from the server
                List<Person> personList = (List<Person>) objectInputStream.readObject();

                // Update the TableView on the JavaFX Application Thread
                Platform.runLater(() -> {
                    tableView.getItems().clear();
                    tableView.getItems().addAll(personList);
                });

                objectInputStream.close();
                clientSocket.close();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
