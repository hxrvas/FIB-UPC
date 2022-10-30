using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class functBarrera : MonoBehaviour
{
    public float velocity = 2f;
    public float velocityM = 7f;
    public bool baixar = true;
    public bool stop = false;
    // Update is called once per frame
    void Update()
    {
        if (transform.position.y >= 1.5) baixar = true;

        else if (transform.position.y < -2) baixar = false;

        if (baixar) transform.Translate(0, -velocity * Time.deltaTime, 0);
        else transform.Translate(0, +velocity * Time.deltaTime, 0);

       if (!stop) transform.Translate(velocityM * Time.deltaTime, 0, 0);
    }
}
