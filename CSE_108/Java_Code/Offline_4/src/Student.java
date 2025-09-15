/* This class stores some basic information of a student, namely a student's name and id.  */
public class Student {
    private String name;
    private String id;

    public Student(String name, String id) {
        this.name = name;
        this.id = id;
    }

    // Task: Write getters and setters as required
    public void setname(String name)
    {
        this.name=name;
    }
    public void setid(String id)
    {
        this.id=id;
    }

    public String getname()
    {
        return this.name;
    }
    public String getid()
    {
        return this.id;
    }

    
    public void showDetails() {
        System.out.println("  Name: "+name+", Id: "+id);
    }
}
