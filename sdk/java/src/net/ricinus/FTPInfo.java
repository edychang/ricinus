package net.ricinus;

public class FTPInfo {

    public FTPInfo() {
    }

    public FTPInfo(String server, Integer port, String userid, String password,
            String remotedir) {
        this.server = server;
        this.port = port;
        this.userid = userid;
        this.password = password;
        this.remotedir = remotedir;
    }

    private String server;
    private Integer port;
    private String userid;
    private String password;
    private String remotedir;

    // auto generated getters/setters
    public String getServer() {
        return server;
    }

    public void setServer(String server) {
        this.server = server;
    }

    public Integer getPort() {
        return port;
    }

    public void setPort(Integer port) {
        this.port = port;
    }

    public String getUserid() {
        return userid;
    }

    public void setUserid(String userid) {
        this.userid = userid;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getRemotedir() {
        return remotedir;
    }

    public void setRemotedir(String remotedir) {
        this.remotedir = remotedir;
    }
}
