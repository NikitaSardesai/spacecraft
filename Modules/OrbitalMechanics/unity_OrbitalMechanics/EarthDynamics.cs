using UnityEngine;
using System.Collections;

public class EarthDynamics : MonoBehaviour {

    private Rigidbody rb;
    public Rigidbody PrimaryBody;
    private float G = 1;
    private float earthMass = 1000;
    private float satMass = 10;
    private float rNorm;
    private Vector3 gravity, r, satVel;

    void Start()
    {

        rb = GetComponent<Rigidbody>();
        rb.useGravity = false;
        rb.mass = satMass;

        float g;
        float v;
        Vector3 rv;

        r = PrimaryBody.GetComponent<Rigidbody>().transform.position - rb.GetComponent<Rigidbody>().transform.position;
        gravity = r;
        rNorm = r.magnitude;
        g = G * earthMass * satMass / Mathf.Pow(rNorm, 2);
        v = 0;
        rv = new Vector3((Random.value - 0.5f), (Random.value - 0.5f), (Random.value - 0.5f));
        satVel = Vector3.Cross(r, rv);
        satVel.Normalize();
        satVel.Scale(new Vector3(v, v, v));
        rb.velocity = satVel;;
    }

    void FixedUpdate()
    {
        float g;

        r = PrimaryBody.GetComponent<Rigidbody>().transform.position - rb.GetComponent<Rigidbody>().transform.position;
        gravity = r;
        rNorm = r.magnitude;
        g = G * earthMass * satMass / Mathf.Pow(rNorm, 3);
        gravity.Scale(new Vector3(g, g, g));
        rb.AddForce(gravity);
    }
}
