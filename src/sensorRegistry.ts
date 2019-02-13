export enum connectionType {
    ws = "ws",
    http = "http"
}

export interface ISensorData {
    ip: string
    connection: connectionType
    frequency: number
}

export class SensorRegistry {

    private registry: ISensorData[]

    public popuplate = (data: ISensorData[]) => {
        this.registry = data
    }

    public connect = () => {
        for(let sensor of this.registry)
        {
            console.log(sensor)
        }
    }
}
