import * as WebSocket from "ws"

export enum connectionType {
    ws = "ws",
    http = "http"
}

export interface INodeMetadata {
    id: string
    url: string
    connection: connectionType
    frequency: number
}

export interface INodeData {
    err: string
    sensors: ISensor[]
}

export interface INodeStatus{
    error : string
    metadata : INodeMetadata
    currentTimestamp: number
}

export interface ISensor {
    id: string
    values: ITimestampedRecord[]
}

export interface ITimestampedRecord {
    timestamp: number
    value: number
}

export class SensorRegistry {

    private registry: INodeMetadata[]

    public popuplate = (data: INodeMetadata[]) => {
        this.registry = data
    }

    public dial = () => {
        for (const node of this.registry) {
            if (node.connection === connectionType.http) {
                this.connectHttpNode(node)
            }
            else if (node.connection === connectionType.ws) {
                this.connectWsNode(node)
            }
        }
    }

    public connectHttpNode = (node: INodeMetadata) => {

    }

    public connectWsNode = (node: INodeMetadata) => {

        const ws = new WebSocket(node.url);

        ws.on('open', () => {
            ws.send('something');
            console.log(`Connection to ${node.id} stablished`)
        });

        ws.on('message', (data:INodeData) => {
            console.log(data);
        });
    }
}

