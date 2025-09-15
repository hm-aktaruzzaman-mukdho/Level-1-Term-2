

public class Food {
    private int RestaurantId;
    private String Catagory;
    private String Name;
    private double Price;

    Food(int RestaurantId,String Catagory,String Name,double Price)
    {
        this.RestaurantId=RestaurantId;
        this.Catagory=Catagory;
        this.Name=Name;
        this.Price=Price;
    }

    Food()
    {
        this.RestaurantId=0;
        this.Catagory=null;
        this.Name=null;
        this.Price=0;

    }

    Food(String inpuString)
    {
        //Split this string and get every data element.
        String[] temp=inpuString.split(",",-1);
        this.RestaurantId=Integer.parseInt(temp[0]);
        this.Catagory=temp[1];
        this.Name=temp[2];
        this.Price=Double.parseDouble(temp[3]);
    }

    // public void setRestaurantId(int RestaurantId) {
    //     this.RestaurantId = RestaurantId;
    // }

    // public void setCatagory(String Catagory) {
    //     this.Catagory = Catagory;
    // }

    // public void setName(String Name) {
    //     this.Name = Name;
    // }

    // public void setPrice(Double Price) {
    //     this.Price = Price;
    // }

    public int getRestaurantId() {
        return this.RestaurantId;
    }

    public String getCatagory() {
        return this.Catagory;
    }

    public String getName() {
        return this.Name;
    }

    public double getPrice() {
        return this.Price;
    }

    public boolean equals(Food obj)
    {
        if(this.RestaurantId==obj.RestaurantId && this.Name.equalsIgnoreCase(obj.Name)&& this.Price==Price && this.Catagory.equalsIgnoreCase(obj.Catagory))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    public boolean DoesNameContains(String subname)
    {
        //String tempname=Name.toUpperCase();
        subname=subname.trim();
        if(subname.equals(""))
        {
            return false;//If empty or space is inputted return false.
        }
        if(Name.toUpperCase().contains(subname.toUpperCase()))
        {
            return true;
        }
        else
            return false;
    }

    public String Foodcontentforfile()
    {
        return new String(RestaurantId+","+Catagory+","+Name+","+Price);
    }

    public String FoodcontentforConsole()
    {
        String outString;
        outString="Name : "+Name+"\nCatagory : "+Catagory+"\nPrice : "+Price + "\n Restaurant ID : "+RestaurantId;

        return outString;
    }
}
