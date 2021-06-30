package datahora;

public class Hora 
{
    public int hora;
    public int min;
    public int seg;

    public Hora(int hora, int min, int seg) {
        this.hora = hora;
        this.min = min;
        this.seg = seg;
    }

    public int getHora() {
        return hora;
    }

    public void setHora(int hora) {
        this.hora = hora;
    }

    public int getMin() {
        return min;
    }

    public void setMin(int min) {
        this.min = min;
    }

    public int getSeg() {
        return seg;
    }

    public void setSeg(int seg) {
        this.seg = seg;
    }

    @Override
    public String toString() {
        return "Hora{" + "hora=" + hora + ", min=" + min + ", seg=" + seg + '}';
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Hora other = (Hora) obj;
        if (this.hora != other.hora) {
            return false;
        }
        if (this.min != other.min) {
            return false;
        }
        if (this.seg != other.seg) {
            return false;
        }
        return true;
    } 
    
}
