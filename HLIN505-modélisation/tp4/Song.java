package tp4;

import java.io.IOException;
import java.io.File;

public class Song extends AbstractAudioElement {
    private String singer;
    private int duration;
    
   
    public Song(String title, String fileLocation, String singer, int duration) throws IncorrectFileNameException {
	super(title, fileLocation);
	this.singer = singer;
	this.duration = duration;
	if (!getFile().exists()) {
	    throw new IncorrectFileNameException(fileLocation);
	}
    }

    public String getSinger() { return singer; }
    public void setSinger(String singer) { this.singer = singer; }
    
    @Override
    public int getDuration() { return duration; }
    public void setDuration(int duration) { this.duration = duration; }

    public long getFileLengh() { return super.file.lengh(); }
}
