/* This class stores the following information about an event: name, starting date, location and list of students registered for the event. */
public class Event {
    private String eventName;
    private String eventDate; // store in the format YYYY-MM-DD
    private String eventLocation;
    private Student[] registeredStudents;
    private int participantsAdded = 0; // variable to keep track of number of participants so far added

    private int maximumParticipants;

    // Task: Write code for the constructor below to initialize the member variables
    // properly
    public Event(String eventName, String eventDate, String eventLocation, int maximumParticipants) {
        // write your code here
        this.eventName = eventName;
        this.eventDate = eventDate;
        this.eventLocation = eventLocation;
        this.maximumParticipants = maximumParticipants;
        this.registeredStudents=new Student[maximumParticipants];//Memory allocation for array of type student.
    }

    // Task: Write getters and setters for Event attributes as required
    public void seteventName(String eventName) {
        this.eventName = eventName;
    }

    public void seteventDate(String eventDate) {
        this.eventDate = eventDate;
    }

    public void seteventLocation(String eventLocation) {
        this.eventLocation = eventLocation;
    }

    public String geteventName() {
        return this.eventName;
    }

    public String geteventDate() {
        return this.eventDate;
    }

    public String geteventLocation() {
        return this.eventLocation;
    }

    public int getparticipants()
    {
        return this.participantsAdded;
    }

    // Task: Write your code for the function below. This functions adds a
    // participant to this event. Check for the following cases: (i) total
    // participant count does not exceed the maximum participant count, (ii) the
    // studentId is not already added.
    public void addParticipant(Student student) {
        // write your code here
        if (isRegistered(student.getid())) {
            System.out.print(student.getid()+" already registered in "+eventName);
        }
        else if((participantsAdded > maximumParticipants))
        {
            System.out.println("Maximum Numbers of Participants already added");
        }
        else
        {
            registeredStudents[participantsAdded] = student;
            participantsAdded++;
        }
    }

    // Task: Write code for the function below. This function shows the details of
    // an event. Make sure your output matches with the supplied sample output.
    public void showDetails() {
        // Write your code here
        System.out.println("Name:" + eventName);
        System.out.println("Date:" + eventDate);
        System.out.println("Location:" + eventLocation);
        System.out.println("Regestered Participants:");
        for (int i = 0; i < participantsAdded; i++) {
            registeredStudents[i].showDetails();
        }
        //System.out.println();

    }

    // Task: Write code for the function below. This function check whether the
    // studentId in the argument has registered for this event or not. Return true
    // if registered, otherwise return false.
    public boolean isRegistered(String studentId) {
        // Write your code here
        boolean flag = false;
        for (int i = 0; i < participantsAdded; i++) {
            if (registeredStudents[i].getid().equals(studentId)) {
                flag = true;
                break;
            }
        }
        return flag;
    }

    // Task: Write code for the function below. This function removes a participant
    // from this event. Check for the following cases: (i) the student Id is not
    // regiseterd.
    public void removeParticipant(String studentId) {
        // Write your code here
        if (isRegistered(studentId)) {
            int positioninarray = 0;
            for (int i = 0; i < participantsAdded; i++) {
                if (registeredStudents[i].getid().equals(studentId)) {
                    positioninarray = i;
                    break;
                }
            }
            for (int i = positioninarray; i < participantsAdded - 1; i++) {
                registeredStudents[i] = registeredStudents[i + 1];
            }
            System.out.println("Successfully removed id " + studentId + " from event " + eventName);
            participantsAdded--;
        }
    }

}