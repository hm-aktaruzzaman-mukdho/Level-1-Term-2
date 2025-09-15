package tcpobject;

import java.io.Serializable;

public class Data implements Serializable {
    private int id;
    private String value;

    public Data(int id,String value)
    {
        this.id=id;
        this.value=value;
    }

    public Data()
    {}

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getValue() {
        return value;
    }

    public void setValue(String value) {
        this.value = value;
    }
}