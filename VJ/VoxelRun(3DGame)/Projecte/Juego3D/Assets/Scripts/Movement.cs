using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;


public class Movement : MonoBehaviour
{
    public GameObject morision;
    public GameLogic logic;
    public CharacterController controller;
    public float speed = 6f;
    public Animator animator;
    public float gravity = -9.82f;
    public Transform groundCheck;
    public float groundDistance = 0.4f;
    public LayerMask groundMask;
    public float jumpHeight = 5f;
    public bool active = false;
    public float v = 7f;
    Vector3 velocity; 
    bool isGrounded;
    public bool isGiant;
    private bool slowDown;
    private Vector3 scale;
    public bool hasWon = false;
    public bool stop = false;
    public bool godMode = false;
    bool entremGiant = false;
    // Update is called once per frame
    private void Start()
    {
        animator.SetBool("IsActive", active);
        scale = transform.localScale;
    }
    void Update()
    {
        if (!hasWon)
        {
            if (active)
            {

                isGrounded = Physics.CheckSphere(groundCheck.position, groundDistance, groundMask);

                if (isGrounded && velocity.y < 0)
                {
                    if (!PauseMenu.paused) FindObjectOfType<AudioManager>().Play("Run");
                    velocity.y = -2f;
                    if (Mathf.Abs(transform.position.z) > 1 && !slowDown)
                    {
                        Vector3 correct = new Vector3(0, 0, -transform.position.z);
                        controller.Move(correct * Time.deltaTime);
                    }
                }
                else FindObjectOfType<AudioManager>().Stop("Run");
                if (slowDown)
                {
                    Vector3 slow = new Vector3(0, 0, -v * 0.5f);
                    controller.Move(slow * Time.deltaTime);
                }

                float horizontal = Input.GetAxisRaw("Horizontal");
                Vector3 direction = new Vector3(horizontal, 0f, 0f).normalized;

                transform.rotation = Quaternion.Euler(0, 0, 0);

                if (direction.magnitude >= 0.1f)
                {
                    controller.Move(direction * speed * Time.deltaTime);
                }

                velocity.y += gravity * Time.deltaTime;
                controller.Move(velocity * Time.deltaTime);



                Vector3 y = new Vector3(0, 1, 0);
                transform.Rotate(y, 200 * Time.deltaTime);

                if (isGiant)
                {
                    if (!entremGiant)
                    {
                        entremGiant = true;
                        GameObject[] allObjects = GameObject.FindGameObjectsWithTag("Terrain");
                        foreach (GameObject obj in allObjects)
                        {
                            if (obj.GetComponent<MoveTerrain>() != null) obj.GetComponent<MoveTerrain>().velocity *= 1.5f;
                        }
                    }
                    Vector3 R = new Vector3(0.5f * Time.deltaTime, 0.4f * Time.deltaTime, 0.7f * Time.deltaTime);
                    scale -= 1.5f * R;
                    transform.localScale = Vector3.Lerp(transform.localScale, scale, 20f * Time.deltaTime);
                    if (scale.x < 0f) Die();
                }

            }
            else if (!stop)
            {
                Vector3 move = new Vector3(0, 0, -v);
                controller.Move(move * Time.deltaTime);
            }
        }
        else
        {
            animator.SetBool("hasWon", hasWon);
            FindObjectOfType<AudioManager>().Stop("Theme");
            FindObjectOfType<AudioManager>().Play("Win");

            isGrounded = Physics.CheckSphere(groundCheck.position, groundDistance, groundMask);

            if (isGrounded && velocity.y < 0)
            {
                velocity.y = -2f;
                if (Mathf.Abs(transform.position.z) > 1 && !slowDown)
                {
                    Vector3 correct = new Vector3(0, 0, -transform.position.z);
                    controller.Move(correct * Time.deltaTime);
                }
            }

            velocity.y += gravity * Time.deltaTime;
            controller.Move(velocity * Time.deltaTime);

        }

    }

    //Detect collisions between the GameObjects with Colliders attached
    void OnTriggerEnter(Collider collision)
    {
        if (active) { 
            //Check for a match with the specified name on any GameObject that collides with your GameObject
            if (collision.gameObject.tag == "Player")
            {
                Movement companion = collision.gameObject.GetComponent<Movement>();
                
                if (!companion.active)
                {
                    FindObjectOfType<AudioManager>().Play("PickUp");
                    print("We add one");
                    logic.addOne(companion);
                    companion.Activate();
                }
            }
            
            else if (collision.gameObject.tag == "Dead")
            {
                if (!godMode) Die();
            }
        }
    }

 
    public void Die()
    {
        FindObjectOfType<AudioManager>().Play("Death");
        print("We remove one");
        logic.removeOne(this);
        Instantiate(morision, transform.position, Quaternion.identity);
        Destroy(gameObject);
    }
    public void SetLogic(GameLogic l)
    {
        logic = l;
    }
    public void ActivateSlowDown ()
    {
        slowDown = true;
    }

    public void DeactivateSlowDown()
    {
        slowDown = false;
    }

    public void addScale(int c)
    {
        Vector3 C = new Vector3(c*0.5f, c*0.4f, c*0.7f);  
        if (scale.x <= 6f) scale += C;
    }

    public float getScale()
    {
        return scale.x;
    }
    public void Activate()
    {
        active = true;
        animator.SetBool("IsActive", active);
    }

    public void Jump(float minZ)
    {
        if (isGrounded)
        {
            float delay = Mathf.Abs(minZ + transform.position.z);
            Invoke("JumpDelay", delay*0.1f);
        }
    }

    public float getZ()
    {
        return transform.position.z;
    }


    public void JumpDelay()
    {
        velocity.y = Mathf.Sqrt(jumpHeight * -2f * gravity);
        int r = Random.Range(0, 8);

        switch (r)
        {
            //case 7:
                //animator.SetTrigger("Backflip");
                //break;
            //case 6:
                //animator.SetTrigger("Frontflip");
                //break;
            default:
                animator.SetTrigger("Jump");
                break;
        }
    }
}
