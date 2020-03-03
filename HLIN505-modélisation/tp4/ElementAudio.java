package tp4;

public interface ElementAudio {
    public abstract int getDuration(); // en seconde
    public abstract String getTitle();
    public abstract String getFileLocation(); // chemin absolu
    public abstract int getTaille();

    public boolean isSong();
    public boolean isPlayList();
}
