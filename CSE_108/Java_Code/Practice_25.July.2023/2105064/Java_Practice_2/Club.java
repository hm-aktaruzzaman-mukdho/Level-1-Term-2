public class Club {
    private int id;
    private String name;
    private Player[] players;
    private int playerCount = 0;
    // add your code here

    // you are not allowed to write any other constructor
    public Club() {
        this.players = new Player[11];
    }

    public double getSalary() {
        double total = 0;
        for (int i = 0; i < playerCount; i++) {
            total += players[i].getSalary();
        }
        return total;
    }

    // add your code here
    // Setters
    public void setId(int id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    // Getters
    public int getId() {
        return this.id;
    }

    public String getName() {
        return this.name;
    }

    public void addPlayer(Player p) {
        players[playerCount] = p;
        playerCount++;
    }

    public Player getMaxSalaryPlayer()
    {
        Player tempPlayer=players[0];
        double maxSalary=players[0].getSalary();
        for(int i=0;i<playerCount;i++)
        {
            if(players[i].getSalary()>maxSalary)
            {
                maxSalary=players[i].getSalary();
                tempPlayer=players[i];
            }
        }

        return tempPlayer;
    }

}