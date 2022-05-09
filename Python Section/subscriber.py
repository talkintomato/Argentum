import random

from paho.mqtt import client as mqtt_client

broker = 'test.mosquitto.org'
port = 1883
topic = "python/temperature"
client_id = f'python-mqtt-{random.randint(0, 100)}'


# Connects to Broker
def connect_mqtt() -> mqtt_client:

    def on_connect(client, userdata, flags, rc):
        if rc == 0:
            print("Connected to MQTT Broker!")
        else:
            print("Failed to connect, return code %d\n", rc)

    client = mqtt_client.Client(client_id)
    client.on_connect = on_connect
    client.connect(broker, port)
    return client


# Starts receiving temperatures and storing them in a file
def subscribe(client, records):

    def on_message(client, userdata, msg):
        messsge = msg.payload.decode()
        temp = float(messsge.split(" ")[0])
        # Record Temperature Recieved
        records.append(temp)
        print(f"Received `{msg.payload.decode()}` from `{msg.topic}` topic")
        save_temp(records)

    client.subscribe(topic)
    client.on_message = on_message
    client.loop_start()


# Lists highest and lowest temperatures recorded
def list_temp(records):
    # Check if no temperature has been recorded
    if (len(records) == 0):
        print("No Temperatures Recorded")
        return

    highest = max(records)
    lowest = min(records)
    print(f'Highest: {highest} deg.C \nLowest: {lowest} deg.C')


# Unsubscribes from broker
def unsubscribe(client):
    client.loop_stop()
    print("Stopped Subscription")


# Clears Temperatures Recorded
def clear_records(records):
    records.clear()
    save_temp(records)
    print("Records cleared")


# Parses and executes users commands
def parse_cmd(cmd, client, records):
    if (cmd == "start"):
        subscribe(client, records)
        print("Started Subscription...")
    elif (cmd == "stop"):
        unsubscribe(client)
    elif (cmd == "clear"):
        clear_records(records)
    elif (cmd == "list"):
        list_temp(records)
    else:
        print("Invalid Command")


# Writes records to file
def save_temp(records):
    f = open("temperatures.txt", "w")
    f.write(f"[{', '.join(str(t) for t in records)}]")
    f.close()


if __name__ == '__main__':
    # Welcome Statement
    print("Welcome to MQTT Temperature subscription" +
          "\nCommands available: " + "\n1. start, stop, clear, list")
    # Establish Connection to Mosquitto
    client = connect_mqtt()

    # list of Temperatures Recorded
    records = []

    while True:
        cmd = input("Enter Command: \n")
        parse_cmd(cmd, client, records)
