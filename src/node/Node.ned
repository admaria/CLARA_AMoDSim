package src.node;

//
// A "Node" consists of a Routing plus an App module
//
module Node
{
    parameters:
        int address;
        int x;
        int y;
        bool isRequestGenerator = default(false);
        string appType;
        string routingType = default("Routing");
        @display("b=,,green");


    gates:
        inout port[];

    submodules:
        initializer: NodeInitializer {
            parameters:
                address = address;
                @display("p=228,130");
        }

        trsubmitter: TripRequestSubmitter if isRequestGenerator {
            parameters:
                address = address;
                @display("p=228,70");
        }
        app: <appType> like IApp {
            parameters:
                address = address;
                @display("p=140,60");
        }

        routing: <routingType> like IRouting {
            parameters:
                @display("p=140,130");
            gates:
                in[sizeof(port)];
                out[sizeof(port)];
        }
        queue[sizeof(port)]: L2Queue {
            parameters:
                @display("p=80,200,row");
        }


    connections:
        routing.localOut --> app.in;
        routing.localIn <-- app.out;
        for i=0..sizeof(port)-1 {
            routing.out[i] --> queue[i].in;
            routing.in[i] <-- queue[i].out;
            queue[i].line <--> port[i];
        }
}


