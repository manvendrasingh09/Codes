ORG 0000H
	MOV SP, #0x07 
	MOV R0, #0x60 
	MOV R1, #0x70 
	MOV R2, #0x80 
	MOV R3, #0x90 
	MOV R4, #0xA0  

	PUSH 0         
	PUSH 1      
	PUSH 2    
	PUSH 3        
	PUSH 4        

	POP 4          
	POP 3
	POP 2
	POP 1
	POP 0
END