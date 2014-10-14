package net.ricinus;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class ProgramAdmin {

    public interface InstallFinishedHandler {
        public void call(Integer ret, String msg);
    }

    public interface UninstallFinishedHandler {
        public void call(Integer ret, String msg);
    }

    private Admin admin_;
    private InstallFinishedHandler ifHandler_;
    private UninstallFinishedHandler ufHandler_;

    public ProgramAdmin(Admin admin) {
        this.admin_ = admin;
    }

    Integer install(String id, String path) {
        // TODO
        return 0;
    }

    Integer uninstall(String id) {
        // TODO
        return 0;
    }

    void setInstallFinishedHandler(InstallFinishedHandler handler) {
        this.ifHandler_ = handler;
    }

    void setUninstallFinishedHandler(UninstallFinishedHandler handler) {
        this.ufHandler_ = handler;
    }

    Boolean isInstalled(String id) {
        // TODO
        return false;
    }

    List<String> getAllInstalled() {
        // TODO
        return new ArrayList<String>();
    }

    List<Schedule> getSchedule(Date from, Date to) {
        // TODO
        return new ArrayList<Schedule>();
    }
}
