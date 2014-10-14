package net.ricinus;

import java.util.Date;

public class Schedule {

    public Schedule(Date start, Date end, String programid) {
        this.start = start;
        this.end = end;
        this.programid = programid;
    }

    public Date getStart() {
        return start;
    }

    public Date getEnd() {
        return end;
    }

    public String getProgramid() {
        return programid;
    }

    private Date start;
    private Date end;
    private String programid;
}
