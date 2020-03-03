package tp7;

import java.util.*;
import java.lang.*;

public class PersonnageInvisible extends Personnage
{
  private boolean visible;
  private int temps_invi;
  private int temps_recharge;

  public boolean get_visible() { return visible; }
  public void set_visible(boolean visible) { this.visible = visible; }
  public int get_temps_invi() { return temps_invi; }
  public void set_temps_invi(int temps_invi) { this.temps_invi = temps_invi; }
  public int get_temps_recharge() { return temps_recharge; }
  public void set_temps_recharge(int temps_recharge) { this.temps_recharge = temps_recharge; }

  public PersonnageInvisible(String _nom, int _nb_points, int _nb_vies, boolean _visible, int _temps_invi, int _temps_recharge)
  {
    super(_nom, _nb_points, _nb_vies);
    set_visible(_visible);
    set_temps_invi(_temps_invi);
    set_temps_recharge(_temps_recharge);
  }

  public boolean invisible() 
  {
    if (get_visible())
    {
      set_visible(false);
      return true;
    }
    else
    {
      return false;
    }
  }

  public static void main(String[] args) 
  {
    
  }
}