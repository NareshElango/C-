import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Arrays;
import java.util.HashMap;

class TicketBook {
    static int alb = 2;
    static int amb = 1;
    static int aub = 1;
    static int arac = 1;
    static int awl = 1;

    static List<Integer> lbp = new ArrayList<>(Arrays.asList(1, 2));
    static List<Integer> mbp = new ArrayList<>(Arrays.asList(1));
    static List<Integer> ubp = new ArrayList<>(Arrays.asList(1));
    static List<Integer> rac = new ArrayList<>(Arrays.asList(1));
    static List<Integer> wlp = new ArrayList<>(Arrays.asList(1));

    static Queue<Integer> wllist = new LinkedList<>();
    static Queue<Integer> raclist = new LinkedList<>();
    static List<Integer> bookedTicketList = new ArrayList<>();

    static Map<Integer,Passenger>passenger_stored_data=new HashMap<Integer,Passenger>();
    public void bookticket(Passenger p,int snum,String allotedberth){
        p.number=snum;
        p.alloted=allotedberth;
        passenger_stored_data.put(p.passengerid,p);
        bookedTicketList.add(p.passengerid);
        System.out.println("Passanger Name "+p.name);
        System.out.println("Passenger Id "+p.passengerid);
        System.out.println("age "+p.age);
        System.out.println("passenger gender "+p.gender);
        System.out.println("alloted berth "+snum+" "+allotedberth);
        System.out.println("-------------------------------------------Booked successfully");
    }

    public void racticket(Passenger p, int snum,String racberth){
        p.number=snum;
        p.alloted=racberth;
        passenger_stored_data.put(p.passengerid,p);
        raclist.add(p.passengerid);
        System.out.println("Passanger Name "+p.name);
        System.out.println("Passenger Id "+p.passengerid);
        System.out.println("age "+p.age);
        System.out.println("passenger gender "+p.gender);
        System.out.println("alloted berth "+snum+" "+racberth);
        System.out.println("-------------------------------------------RAC Booked successfully");
    }
    public void wlticket(Passenger p, int snum,String wlberth){
        p.number=snum;
        p.alloted=wlberth;
        passenger_stored_data.put(p.passengerid,p);
        wllist.add(p.passengerid);
        System.out.println("Passanger Name "+p.name);
        System.out.println("Passenger Id "+p.passengerid);
        System.out.println("age "+p.age);
        System.out.println("passenger gender "+p.gender);
        System.out.println("alloted berth "+snum+" "+wlberth);
        System.out.println("-------------------------------------------WL Booked successfully");
    }






    public void passengersdetails() {
    if (passenger_stored_data.size() == 0) {
        System.out.println("No Passengers are registered yet.");
        return;
    } else {
        for (Passenger p : passenger_stored_data.values()) {
            System.out.print("\nID: " + p.passengerid);
            System.out.print("\nName: " + p.name);
            System.out.print("\nAge: " + p.age);
            System.out.print("\nGender: " + p.gender);
            System.out.print("\nAllotted berth: " + p.number + p.alloted);
            System.out.println("\n-------------------------------------------");
        }
    }
}

public void cancelticket(int passengerid) {
    Passenger p = passenger_stored_data.get(passengerid);
    passenger_stored_data.remove(passengerid);
    bookedTicketList.remove(passengerid);
    int psnum = p.number;
    System.out.println("Cancelled successfully");

    if (p.alloted.equals("L")) {
        lbp.add(psnum);
        alb++;
    } else if (p.alloted.equals("M")) {
        mbp.add(psnum);
        amb++;
    } else if (p.alloted.equals("U")) {
        ubp.add(psnum);
        aub++;
    }

    if (raclist.size() > 0) {
        Passenger passengerfromrac = passenger_stored_data.get(raclist.poll());
        int pracnum = passengerfromrac.number;
        rac.add(pracnum);
        raclist.remove(passengerfromrac.passengerid);
        arac++;
    }

    if (wllist.size() > 0) {
        Passenger passengerfromwait = passenger_stored_data.get(wllist.poll());
        int pwlnum = passengerfromwait.number;
        wlp.add(pwlnum);
        wllist.remove(passengerfromwait.passengerid);

        passengerfromwait.number = rac.get(0);
        passengerfromwait.alloted = "RAC";
        rac.remove(0);
        raclist.add(passengerfromwait.passengerid);
        awl++;
        arac--;
    }


    Sample.bookticket(passengerfromrac);

    

}

}
