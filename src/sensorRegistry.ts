export enum connectionType {
    ws = "ws",
    http = "http"
}

export interface ISensorData {
    id: string
    ip: string
    connection: connectionType
    frequency: number
}

export class SensorRegistry {

    private registry: ISensorData[]

    public popuplate = (data: ISensorData[]) => {
        this.registry = data
    }

    public dial = () => {
        for (const sensor of this.registry) {
            if (sensor.connection === connectionType.http) {
                this.connectHttpSensor(sensor)
            }
            else if (sensor.connection === connectionType.ws) {
                this.connectWsSensor(sensor)
            }
        }
    }

    public connectHttpSensor = (sensor: ISensorData) => {

    }

    public connectWsSensor = (sensor: ISensorData) => {
    }
}

