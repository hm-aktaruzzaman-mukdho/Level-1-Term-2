import java.util.ArrayList;

public class Java_Collection{

    public static void main(String[] args) {
        ArrayList<Integer> myarraylist=new ArrayList<>();
        for(int i=0;i<20;i++)
        {
            myarraylist.add(i);
        }

        System.out.println(myarraylist);
    }
}