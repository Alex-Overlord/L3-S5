package tp4;

import java.io.*;

public abstract class AbstractAudioElement implements ElementAudio {
    private String title;
    private String fileLocation;
    private File file;

    public AbstractAudioElement(String title, String fileLocation) {
	this.title = title;
	this.fileLocation = fileLocation;
	file = new file(fileLocation);
    }
    
    @Override
    public String getTitle() { return title; }
    public void setTitle(String title) { this.title = title; }
    
    @Override
    public String getFileLocation() { return fileLocation; }
    public void setFileLocation(String fileLocation) { this.fileLocation = fileLocation; }
    
    public File getFile() { return file; }
    public void setFile(String file) { this.file = file; }
}
    
    
