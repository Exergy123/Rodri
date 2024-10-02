#import openai
from openai import OpenAI
#reiniciar el idle despues de cargar la key del API

print("Activando...")
client = OpenAI()

def chatbot(prompt, model="gpt-4o-mini"):
    completion = client.chat.completions.create(
        model=model,
        messages=[
            {"role": "system", "content": "Eres de respuestas cortas."},
            {"role": "user", "content": prompt}
        ]
    )
    #print(completion.choices[0].message)
    return completion.choices[0].message.content
print("Activando...")


# Bucle de chat
print("¡Hola! Soy un chatbot IA con memoria. Escribe 'salir' para terminar la conversación.")
while True:
    prompt = input("Tú: ")
    if prompt.lower() == "salir":
        print("Chatbot: ¡Adiós! Fue un placer charlar contigo.")
        break
    response = chatbot(prompt)
    print("Chatbot:", response)  
